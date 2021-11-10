#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	FILE* fptr = fopen("bonus.txt", "w");
	fprintf(fptr, "I can't write C program. :(\n");
}