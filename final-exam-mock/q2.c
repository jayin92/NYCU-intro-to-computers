
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vector {
    int size;
    int* arr;
    int idx;
} Vector; 

void push_back(Vector* a, int val){
    if(a -> idx >= a -> size * 3 / 4){
        a -> size *= 2;
        a -> arr = (int*)realloc(a -> arr, sizeof(int) * a -> size);
    }
    a -> arr[a -> idx++] = val;
}

void pop_back(Vector* a){
    if(a -> idx != 0) a -> idx --;
    if(a -> idx <= a -> size / 4){
        a -> size /= 2;
        a -> arr = (int*)realloc(a -> arr, sizeof(int) * a -> size);
    }
}

void print(Vector *a){
    for(int i=0;i<a->idx;i++){
        printf("%d ", a -> arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    Vector* v = (Vector*)malloc(sizeof(Vector));
    v -> arr = (int*)malloc(sizeof(int) * 10);
    v -> size = 10;
    v -> idx = 0;
    while(scanf("%d", &n) != EOF){
        if(n == -1){
            pop_back(v);
        } else {
            push_back(v, n);
        }

        print(v);
    }

}
