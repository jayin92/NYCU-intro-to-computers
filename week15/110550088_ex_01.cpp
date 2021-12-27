#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXN 100

void swap(int &a, int &b);
void bubbleSort(int a[], int size);
void selectionSort(int a[], int size);
void insertionSort(int a[], int size);
void printArray(int a[], int size);

int main() {
    int bub[MAXN], sel[MAXN], ins[MAXN];
    double START, END, TIMEBUB, TIMESEL, TIMEINS;
    FILE* fptr1 = fopen("data1.txt", "r");
    FILE* fptr2 = fopen("data2.txt", "r");
    FILE* fptr3 = fopen("data3.txt", "r");
    for(int i=0;i<MAXN;i++){
        fscanf(fptr1, "%d", bub+i);
    }

    for(int i=0;i<MAXN;i++){
        fscanf(fptr2, "%d", sel+i);
    }

    for(int i=0;i<MAXN;i++){
        fscanf(fptr3, "%d", ins+i);
    }
    
    START = clock();
    bubbleSort(bub, MAXN);
    END = clock();
    TIMEBUB = END - START;
    printf("TIMEBUBBLE = %lf\n", TIMEBUB / (double)CLOCKS_PER_SEC);

    START = clock();
    selectionSort(sel, MAXN);
    END = clock();
    TIMESEL = END - START;
    printf("TIMESELECTION= %lf\n", TIMESEL / (double)CLOCKS_PER_SEC);

    START = clock();
    insertionSort(ins, MAXN);
    END = clock();
    TIMEINS = END - START;
    printf("TIMEINSERTION = %lf\n", TIMEINS / (double)CLOCKS_PER_SEC);

    printArray(bub, MAXN);
    printArray(sel, MAXN);
    printArray(ins, MAXN);

    system("pause");
    return 0;
}

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(int a[], int size){
    for(int i=1;i<=size-1;i++){
        for(int j=0;j<size-i;j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

void selectionSort(int a[], int size){
    for(int i=0;i<size-1;i++){
        int idx = i;
        int min = a[i];
        for(int j=i;j<size;j++){
            if(min > a[j]){
                min = a[j];
                idx = j;
            }
        }
        swap(a[i], a[idx]);
    }
}

void insertionSort(int a[], int size){
    for(int i=1;i<size;i++){
        int tmp = a[i];
        int j = i-1;
        while(tmp < a[j] && j >= 0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp; 
    }
}

void printArray(int a[], int size){
    for(int i=0;i<size;i++){
        printf("%d ", a[i]);
        if((i+1) % 10 == 0) printf("\n");
    }
    printf("\n");
}