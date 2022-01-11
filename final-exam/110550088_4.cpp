#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "q4data.c"

void print(node* a) {
	node* cur = a;
	while (cur != NULL) {
		printf("%d ", cur->number);
		cur = cur->next;
	}
	printf("\n");
}

int main() {
	node* A = data_a();
	node* B = data_b();

	printf("A: ");
	print(A);
	printf("B: ");
	print(B);

	node* merged = (node*)malloc(sizeof(node));
	merged->next = NULL;
	merged->number = -1;
	node* cur = merged;
	node* cura = A;
	node* curb = B;
	while (cura != NULL && curb != NULL) {
		if (cura->number < curb->number) {
			cur->next = cura;
			cura = cura->next;
			cur->next->next = NULL;
			cur = cur->next;
		}
		else {
			cur->next = curb;
			curb = curb->next;
			cur->next->next = NULL;
			cur = cur->next;
		}
	}

	while (cura != NULL || curb != NULL) {
		if (cura != NULL) {
			cur->next = cura;
			cura = cura->next;
			cur->next->next = NULL;
			cur = cur->next;
		}
		else {
			cur->next = curb;
			curb = curb->next;
			cur->next->next = NULL;
			cur = cur->next;
		}
	}
	printf("Merge: ");
	print(merged->next);
}
