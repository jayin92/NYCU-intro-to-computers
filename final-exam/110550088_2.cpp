#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct planet_ {
	char name[20];
	float attr[4];
} Planet;

int main() {
	FILE* fptr = fopen("q2.txt", "r");
	int n, attr;
	double val;
	printf("please input the number of data.\n");
	scanf("%d", &n);
	printf("please input the chosen attribute.\n");
	scanf("%d", &attr);
	printf("please input the value you want.\n");
	scanf("%lf", &val);

	if (n == 0) return 0;
	Planet* arr = (Planet*)calloc(n, sizeof(Planet));
	for (int i = 0; i < n; i++) {
		fscanf(fptr, "%s %f %e %e %f", arr[i].name, &arr[i].attr[0], &arr[i].attr[1], &arr[i].attr[2], &arr[i].attr[3]);
	}

	int idx = 0;
	float min_dis = fabs(arr[0].attr[attr] - val);
	for (int i = 1; i < n; i++) {
		// printf("%d %llf\n", idx, min_dis);
		if (min_dis > fabs(arr[i].attr[attr] - val)) {
			idx = i;
			min_dis = fabs(arr[i].attr[attr] - val);
		}
	}

	printf("%s %e %e %e %e\n", arr[idx].name, arr[idx].attr[0], arr[idx].attr[1], arr[idx].attr[2], arr[idx].attr[3]);
}