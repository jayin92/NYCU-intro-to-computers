#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b;
	printf("請輸入第一個整數：");
	scanf("%d", &a);
	printf("請輸入第二個整數：");
	scanf("%d", &b);
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	printf("a+b=%d\n", a + b);
	printf("a-b=%d\n", a - b);
	printf("a*b=%d\n", a * b);
	printf("a/b=%.2f\n", (double)a / (double)b);
	printf("a%%b=%d\n", a % b);

	system("pause");
	return 0;
}
