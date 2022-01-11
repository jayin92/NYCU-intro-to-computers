#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print(int a[]) {
	for(int i = 0; i < 7; i++) printf("%d ", a[i]);
	printf("\n");
}

int main() {
	int n = 7;
	int a[7];
	printf("Original Unsorted array : ");
	for (int i = 0; i < 7; i++) {
		scanf("%d", a + i);
	}

	for (int i = 1; i <= n / 2; i++) {
		printf("Forward Pass:\n");
		for (int j = i-1; j < n - i; j++) {
			if (a[j] > a[j + 1]) {
				swap(a + j, a + j + 1);
				print(a);
			}
		}
		printf("Backward Pass:\n");
		for (int j = n - i - 1; j >= i; j--) {
			if (a[j - 1] > a[j]) {
				swap(a + j - 1, a + j);
				print(a);
			}
		}
	}
	printf("Sorted array : ");
	print(a);
}
