#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b, c;
	while(true){
		printf("ax^2+bx+c=0\n");
		printf("Please input a, b and c: ");
		scanf("%d %d %d", &a, &b, &c);
		printf("%dx^2+%dx+%d=0\n", a, b, c);
		int dis = b * b - 4 * a * c;
		if(dis > 0){
			printf("Two distinct real roots.\n");
		} else if(dis == 0){
			printf("Two same real roots.\n");
		} else {
			printf("No real root.\n");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

