#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int sec; 
	printf("Input an positive integer (second): ");
	scanf("%d", &sec);
	int day = sec / (24 * 3600);
	sec %= 24 * 3600;
	int hr = sec / 3600;
	sec %= 3600;
	int minu = sec / 60;
	sec %= 60;
	printf("%d days %d hrs %d min %d s\n", day, hr, minu, sec);

	system("pause");
	return 0;
}
