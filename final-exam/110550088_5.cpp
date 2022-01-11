#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long ans = 0;
char ori[15];
int used[10000][26];
int cnt[26];
int idx = 0;

long long fac(long long n) {
	long long res = 1;
	for (long long i = 1; i <= n; i++) res *= i;

	return res;
}

long long cal(int cnt[], int sz) {
	long long res = fac(sz);
	for (int i = 0; i < 26; i++) {
		res /= fac(cnt[i]);
	}

	return res;
}

void solve(int n, int idx1) {
	if (n == idx1) {
		bool flag = false;
		for (int i = 0; i < idx; i++) {
			int flag1 = 0;
			for (int j = 0; j < 26; j++) {
				if (used[i][j] != cnt[j]) {
					flag1 = true;
					break;
				}
			}
			if (flag1 == false) {
				flag = true;
				break;
			}

		}
		if (flag) return;
		int sz = 0;
		for (int i = 0; i < 26; i++) {
			used[idx][i] = cnt[i];
			sz += cnt[i];
		}
		if (sz == 0) return;
		idx++;
		ans += cal(cnt, sz);
		return;
	}
	cnt[ori[idx1] - 'A'] ++;
	solve(n, idx1 + 1);
	cnt[ori[idx1] - 'A'] --;
	solve(n, idx1 + 1);
}

int main() {
	printf("tiles: ");
	scanf("%s", ori);
	int sz = strlen(ori);
	int cnt[26] = { 0 };
	for (int i = 0; i < 26; i++) cnt[i] = 0;
	solve(sz, 0);
	printf("number of possible non-empty sequences: %lld\n", ans);
}
