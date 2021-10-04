#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	while(true){
		printf("Please enter an integer: ");
		scanf("%d", &n);
		
		switch(n % 2){
			case 0:
				printf("%d is an even number.\n\n", n);
				break;
			case 1:
				printf("%d is an odd number.\n\n", n);
				break;
		}
	}
	
	
	system("pause");
	return 0;
}

