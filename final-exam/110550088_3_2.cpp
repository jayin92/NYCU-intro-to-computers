#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


int main() {
	int a[25005];
	int n = 25000;
	FILE* fptr = fopen("q3.txt", "r");
	for (int i = 0; i < n; i++) {
		fscanf(fptr, "%d", a + i);
	}


	for (int i = 1; i <= n / 2; i++) {
		for (int j = i - 1; j < n - i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a + j, a + j + 1);
			}
		}
		for (int j = n - i - 1; j >= i; j--) {
			if (a[j - 1] > a[j]) {
				swap(a + j - 1, a + j);
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < n - 1; i++) {
		ans += (long long)a[i + 1] - (long long)a[i];
	}
	printf("The minimum value is equal to %lld\n", ans);
}
