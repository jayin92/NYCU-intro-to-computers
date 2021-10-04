#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("What operation would you like to perform?\n");
	printf("\tA) Addition\n");
	printf("\tB) Subtraction\n");
	printf("\tC) Multiplication\n");
	printf("\tD) Division\n");
	char oper, op;
	scanf("%c", &oper);
	double a, b, ans;
	printf("Please enter first number: ");
	scanf("%lf", &a);
	printf("Please enter second number: ");
	scanf("%lf", &b);
	
	if(oper == 'A' || oper == 'a'){
		op = '+';
		ans = a + b;	
	} else if(oper == 'B' || oper == 'b'){
		op = '-';
		ans = a - b;
	} else if(oper == 'C' || oper == 'c'){
		op = '*';
		ans = a * b;
	} else if(oper == 'D' || oper == 'd'){
		op = '/';
		ans = a / b;
	}
	
	printf("%.6f %c %.6f = %.6f\n", a, op, b, ans);
	system("pause");
	return 0;
}

