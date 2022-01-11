#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* nxt;
} Node;


void print(Node* root){
    Node* cur = root;
    while(cur != NULL){
        printf("%d ", cur -> val);
        cur = cur -> nxt;
    }

    printf("\n");
}

int main(){
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {0, 2, 4, 6, 8, 10, 12, 14, 15};

    int sza, szb;
    sza = sizeof(a) / sizeof(int);
    szb = sizeof(b) / sizeof(int);

    Node* roota = (Node*)malloc(sizeof(Node));
    Node* rootb = (Node*)malloc(sizeof(Node));
    roota -> nxt = rootb -> nxt = NULL;
    Node* cur = roota;
    for(int i=0;i<sza;i++){
        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp -> val = a[i];
        tmp -> nxt = NULL;
        cur -> nxt = tmp;
        cur = tmp;
    }

    cur = rootb;
    for(int i=0;i<szb;i++){
        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp -> val = b[i];
        tmp -> nxt = NULL;
        cur -> nxt = tmp;
        cur = tmp;
    }

    Node* cura = roota -> nxt;
    Node* curb = rootb -> nxt;
    Node* merged = (Node*)malloc(sizeof(Node));
    Node* curmer = merged;
    merged -> nxt = NULL;
    while(cura != NULL && curb != NULL){
        if(cura -> val < curb -> val){
            curmer -> nxt = cura;
            cura = cura -> nxt;
            curmer -> nxt -> nxt = NULL;
            curmer = curmer -> nxt;
        } else {
            curmer -> nxt = curb;
            curb = curb -> nxt;
            curmer -> nxt -> nxt = NULL;
            curmer = curmer -> nxt;
        }
    }

    while(cura != NULL || curb != NULL){
        if(cura != NULL){
            curmer -> nxt = cura;
            cura = cura -> nxt;
            curmer -> nxt -> nxt = NULL;
            curmer = curmer -> nxt;
        } else {
            curmer -> nxt = curb;
            curb = curb -> nxt;
            curmer -> nxt -> nxt = NULL;
            curmer = curmer -> nxt;
        }
    }

    print(merged -> nxt);
    
}