#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	const int MAXN = 100000;
	int n, k, ans;
	printf("Input two positive integers N K = ");
	scanf("%d %d", &n, &k);
	int a[MAXN];
	for (int i = 0; i < MAXN; i++) {
		a[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		a[i] = i+1;
	}

	int cur = 0;
	int r = n;
	while (r != 1) {
		int s = k-1;
		while (s != 0) {
			cur++;
			cur %= n;
			if (a[cur] != -1) {
				s--;
			}
		}
		a[cur] = -1;
		for (int i = 1; i <= n; i++) {
			if (a[(cur+i) % n] != -1) {
				cur = cur + i;
				break;
			}
		}
		

		r--;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != -1) {
			printf("The winner is %d", i+1);
		}
	}

	return 0;
}
