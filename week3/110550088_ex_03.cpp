#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf("Input an AD year (smaller than 2021): ");
	scanf("%d", &n);
	if((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)){
		printf("%d year is a leap year\n", n);
	} else {
		printf("%d year is not a leap year\n", n);
	}
	system("pause");
	return 0;
}

