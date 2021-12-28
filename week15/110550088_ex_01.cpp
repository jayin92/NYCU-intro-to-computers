#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXN 25000

void swap(int &a, int &b);
void bubbleSort(int a[], int size);
void selectionSort(int a[], int size);
void insertionSort(int a[], int size);
void printArray(int a[], int size);

int main() {
    int a1[MAXN], a2[MAXN], a3[MAXN];
    int b1[MAXN], b2[MAXN], b3[MAXN];
    int c1[MAXN], c2[MAXN], c3[MAXN];
    double START, END, TIMEBUB[3], TIMESEL[3], TIMEINS[3];
    FILE* fptr1 = fopen("data1.txt", "r");
    FILE* fptr2 = fopen("data2.txt", "r");
    FILE* fptr3 = fopen("data3.txt", "r");
    for(int i=0;i<MAXN;i++){
        fscanf(fptr1, "%d", a1+i);
        b1[i] = c1[i] = a1[i];
    }

    for(int i=0;i<MAXN;i++){
        fscanf(fptr2, "%d", a2+i);
        b2[i] = c2[i] = a2[i];

    }

    for(int i=0;i<MAXN;i++){
        fscanf(fptr3, "%d", a3+i);
        b3[i] = c3[i] = a3[i];
    }
    
    START = clock();
    bubbleSort(a1, MAXN);
    END = clock();
    TIMEBUB[0] = END - START;

    START = clock();
    bubbleSort(a2, MAXN);
    END = clock();
    TIMEBUB[1] = END - START;

    START = clock();
    bubbleSort(a3, MAXN);
    END = clock();
    TIMEBUB[2] = END - START;
    

    START = clock();
    selectionSort(b1, MAXN);
    END = clock();
    TIMESEL[0] = END - START;

    START = clock();
    selectionSort(b2, MAXN);
    END = clock();
    TIMESEL[1] = END - START;

    START = clock();
    selectionSort(b3, MAXN);
    END = clock();
    TIMESEL[2] = END - START;

    START = clock();
    insertionSort(c1, MAXN);
    END = clock();
    TIMEINS[0] = END - START;

    START = clock();
    insertionSort(c2, MAXN);
    END = clock();
    TIMEINS[1] = END - START;

    START = clock();
    insertionSort(c3, MAXN);
    END = clock();
    TIMEINS[2] = END - START;

    printArray(a1, MAXN);
    printArray(b2, MAXN);
    printArray(c3, MAXN);
    printf("TIMEBUBBLE = %lf, %lf, %lf\n", TIMEBUB[0] / (double)CLOCKS_PER_SEC, TIMEBUB[1] / (double)CLOCKS_PER_SEC, TIMEBUB[2] / (double)CLOCKS_PER_SEC);
    printf("TIMESELECTION = %lf, %lf, %lf\n", TIMESEL[0] / (double)CLOCKS_PER_SEC, TIMESEL[1] / (double)CLOCKS_PER_SEC, TIMESEL[2] / (double)CLOCKS_PER_SEC);
    printf("TIMEINSERTION = %lf, %lf, %lf\n", TIMEINS[0] / (double)CLOCKS_PER_SEC, TIMEINS[1] / (double)CLOCKS_PER_SEC, TIMEINS[2] / (double)CLOCKS_PER_SEC);

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