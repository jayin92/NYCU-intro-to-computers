#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b;
	printf("�п�J�Ĥ@�Ӿ�ơG");
	scanf("%d", &a);
	printf("�п�J�ĤG�Ӿ�ơG");
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
