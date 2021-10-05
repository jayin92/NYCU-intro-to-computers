#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	while(true){
		int n;
		printf("Please input month: ");
		scanf("%d", &n);
		switch(n){
			case 1:
				printf("Winter!\n");
				break;
			case 2:
				printf("Winter!\n");
				break;
			case 3:
				printf("Spring!\n");
				break;
			case 4:
				printf("Spring!\n");
				break;
			case 5:
				printf("Spring!\n");
				break;
			case 6:
				printf("Summer!\n");
				break;
			case 7:
				printf("Summer!\n");
				break;
			case 8:
				printf("Summer!\n");
				break;
			case 9:
				printf("Autumn!\n");
				break;
			case 10:
				printf("Autumn!\n");
				break;
			case 11:
				printf("Autumn!\n");
				break;
			case 12:
				printf("Winter!\n");
				break;
			default:
				printf("Wrong input!\n");
				break;
		}
	}
	system("pause");
	return 0;
}

