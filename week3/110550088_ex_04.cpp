#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(){
	int a, b, c, oa, ob, oc, aa, bb, cc;
	printf("Input three positive integers (length of the triangle): ");
	scanf("%d %d %d", &a, &b, &c);
	oa = a; ob = b; oc = c;
	if(a < b) swap(&a, &b);
	if(b < c) swap(&b, &c);
	if(a < b) swap(&a, &b);
	aa = a * a;
	bb = b * b;
	cc = c * c;
	if(a >= (b + c)){
		printf("%d %d %d can NOT form a triangle.\n", oa, ob, oc);
	} else {
		printf("%d %d %d can form a triangle.\n", oa, ob, oc);
		if(aa > bb + cc){
			printf("%d %d %d can form a obtuse triangle.\n", oa, ob, oc);
		} else if(aa == bb + cc){
			printf("%d %d %d can form a right triangle.\n", oa, ob, oc);
		} else {
			printf("%d %d %d can form a acute triangle.\n", oa, ob, oc);
		}
		if(a == b || b == c || a == c){
			printf("%d %d %d can form a isosceles triangle.\n", oa, ob, oc);
		}
		if(a == b && b == c){
			printf("%d %d %d can form a equilateral triangle.\n", oa, ob, oc);
		}
	}
	system("pause");
	return 0;
}

