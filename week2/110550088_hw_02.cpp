#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int w, h;
	printf("Height: ");
	scanf("%d", &h);
	printf("Weight: ");
	scanf("%d", &w);
	float bmi = (float)w / ((float)h/100.0 * (float)h/100.0);
	printf("BMI: %.2f\n", bmi);
	printf("BMI after rounding: %.2f\n", round(bmi));
	
	system("pause");
	return 0;
}

