#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char name[1000];
    int is_dir;
    int size;
    struct Node** children;
    int children_sz;
} Node;

int idx;

char** split(char s[]){
    char** res = (char**)calloc(100, sizeof(char*));
    for(int i=0;i<100;i++) res[i] = (char*)calloc(105, sizeof(char));
    int sz = strlen(s);
    idx = 0;
    char tmp[100];
    strcpy(tmp, "");
    for(int i=0;i<sz;i++){
        if(s[i] != '/'){
            int szz = strlen(tmp);
            tmp[szz] = s[i];
            tmp[szz+1] = '\0';
        } else if(s[i] == '/'){
            if(strcmp(tmp, "") != 0){
                strcpy(res[idx++], tmp);
                strcpy(tmp, "");
            }
        }
    }

    if(strlen(tmp) > 0) strcpy(res[idx++], tmp);

    return res;
}


int main(){
    int in_sz;
    scanf("%d", &in_sz);
    char dir[1000];
    int f_size;
    Node* root = (Node*)malloc(sizeof(Node));
    root -> is_dir = 1;
    root -> children_sz = 0;
    root -> children = (Node**)calloc(1000, sizeof(Node*));
    strcpy(root -> name, "");

    for(int i=0;i<in_sz;i++){
        scanf("%s %d", dir, &f_size);
        char** res = split(dir);
        // printf("%d\n", idx);
        // for(int j=0;j<idx;j++){
        //     printf("%s ", res[j]);
        // }
        Node* cur = root;
        for(int j=0;j<idx-1;j++){            
            int found = 0;
            int k;
            for(k=0;k <cur -> children_sz;k++){
                if(strcmp(cur -> children[k] -> name, res[j]) == 0 && cur -> children[k] -> is_dir == 1){
                    found = 1;
                    break;
                }
            }
            if(!found){
                Node* tmp = (Node*)malloc(sizeof(Node));
                tmp -> children_sz = 0;
                tmp -> is_dir = 1;
                strcpy(tmp -> name, res[j]);
                tmp -> size = -1;
                tmp -> children = (Node**)calloc(1000, sizeof(Node*));
                cur -> children[cur -> children_sz] = tmp;
                cur -> children_sz ++;
                cur = tmp;
            } else {
                cur = cur -> children[k];
            }
        }

        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp -> children_sz = 0;
        tmp -> is_dir = 0;
        strcpy(tmp -> name, res[idx-1]);
        tmp -> size = f_size;
        cur -> children[cur -> children_sz] = tmp;
        cur -> children_sz ++;        
    }
    int req_sz;
    scanf("%d", &req_sz);
    int total_file_size, file_cnt, dir_cnt;
    for(int i=0;i<req_sz;i++){
        scanf("%s", dir);
        char** res = split(dir);
        Node* cur = root;
        int flag = 1;
        for(int j=0;j<idx;j++){
            flag = 1;
            for(int k=0;k<cur->children_sz;k++){
                if(cur->children[k] -> is_dir == 1 && strcmp(cur->children[k]->name, res[j]) == 0){
                    cur = cur -> children[k];
                    flag = 0;
                    break;
                }
            }
            if(flag) break;
        }

        if(idx != 0 && flag){
            printf("invalid path\n");
            continue;
        }
        dir_cnt = file_cnt = total_file_size = 0;
        for(int j=0;j<cur->children_sz;j++){
            if(cur -> children[j] -> is_dir == 1){
                dir_cnt ++;
            } else {
                file_cnt ++;
                total_file_size += cur -> children[j] -> size;
            }
        }
        printf("%d %d %d\n", dir_cnt, file_cnt, total_file_size);
    }

}