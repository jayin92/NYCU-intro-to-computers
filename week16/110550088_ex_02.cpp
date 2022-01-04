#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c) {
	if (a >= b && a >= c) return a;
	if (b >= a && b >= c) return b;
	if (c >= a && c >= b) return c;
}

int min(int a, int b, int c) {
	if (a <= b && a <= c) return a;
	if (b <= a && b <= c) return b;
	if (c <= a && c <= b) return c;
}

int main() {
	FILE* fptr = fopen("p5.txt", "r");
	int arr[205];
	int n = 200;
	for (int i = 0; i < n; i++) {
		fscanf(fptr, "%d", arr + i);
	}
	int a, b, c;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				a = arr[i]; b = arr[j]; c = arr[k];
				if (max(a, b, c) - min(a, b, c) <= 2) ans++;
			}
		}
	}

	printf("The number of Close Tuples is %d\n", ans);
	system("PAUSE");


}