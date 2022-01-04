#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Student
{
	char name[100];
	bool sex;
	double data[4]; // height, weight, bld_p, bld_l
};

typedef struct Student Student;
int main() {
	FILE* fptr = fopen("patients_data.txt", "r");

	int sz, sex, attr;
	double l, r;
	printf("please input the size of data.\n");
	scanf("%d", &sz);
	Student* a = (Student*)calloc(sz, sizeof(Student));
	printf("please input which sex we want to select.\n");
	scanf("%d", &sex);
	printf("please input which attribute we want to choose.\n");
	scanf("%d", &attr);
	printf("please input the range of concern.\n");
	scanf("%lf %lf", &l, &r);

	for (int i = 0; i < sz; i++) {
		fscanf(fptr, "%s %d %lf %lf %lf %lf", &a[i].name, &a[i].sex, &a[i].data[0], &a[i].data[1], &a[i].data[2], &a[i].data[3]);
	}
	
	for (int i = 0; i < sz; i++) {
		if ((sex == 2 || a[i].sex == sex) && (l < a[i].data[attr] && a[i].data[attr] < r)) {
			printf("%s %d %lf %lf %lf %lf\n", a[i].name, a[i].sex, a[i].data[0], a[i].data[1], a[i].data[2], a[i].data[3]);
		}
	}

	system("PAUSE");

	

}