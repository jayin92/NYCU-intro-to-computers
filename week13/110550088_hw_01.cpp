#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int id;
    int money;
    Node* nxt = NULL;
} Node;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    char tmpc[100];
    scanf("%s %s %s %s", tmpc, tmpc, tmpc, tmpc);
    Node* root = new Node;
    root -> nxt = NULL;
    root -> id = -1;
    root -> money = -1;
    for(int i=0;i<n;i++){
        int sz, id, money, pos;
        scanf("%d", &sz);
        if(sz == 1){
            scanf("%d", &id);
            Node* cur = root;
            int cnt = -1;
            while(cur -> nxt != NULL && cnt < id - 1){
                cur = cur -> nxt;
                cnt ++;
            }
            cur -> nxt = cur -> nxt -> nxt;
        } else if(sz == 2){
            scanf("%d %d", &id, &money);
            Node* cur = root;
            while(cur -> nxt != NULL){
                cur = cur -> nxt;
            }
            Node* tmp = new Node;
            tmp -> id = id;
            tmp -> money = money;
            tmp -> nxt = NULL;
            cur -> nxt = tmp;
        } else if(sz == 3){
            scanf("%d %d %d", &id, &money, &pos);
            Node* cur = root;
            int cnt = -1;
            while(cur -> nxt != NULL && cnt < pos - 1){
                cur = cur -> nxt;
                cnt ++;
            }
            Node* tmp = cur -> nxt;
            Node* new_node = new Node;
            new_node -> id = id;
            new_node -> money = money;
            cur -> nxt = new_node;
            new_node -> nxt = tmp;
        }        
    }
    Node* cur = root -> nxt;
    while(cur != NULL){
        printf("ID money : %d %d\n", cur -> id, cur -> money);
        cur = cur -> nxt;
    }

    system("pause");
    return 0;
}

