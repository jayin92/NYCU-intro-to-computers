#include <stdlib.h>
#include "vector.h"

vector* vector_construct(int length) {
	vector* res = new vector;
	res->length = length;
	res->vec = (int*)calloc(length, sizeof(int));

	return res;
}