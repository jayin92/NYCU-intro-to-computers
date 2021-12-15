#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  _grade{
	int Chinese, Math, English, computer_science;
} grade;

typedef struct student{
	char name[10];                
	int student_id;                 	
	grade student_grade;
} student;


int main() {
    int line[4];
    char subject_name[4][20] = {
        "Chinese",
        "Math",
        "English",
        "ComputerScience",
    };
    printf("Input queries score:\n");
    for(int i=0;i<4;i++){
        char sub[20];
        int score;
        scanf("%s %d", sub, &score);
        if(strcmp(sub, "C") == 0){
            line[0] = score;
        } else if(strcmp(sub, "M") == 0){
            line[1] = score;            
        } else if(strcmp(sub, "E") == 0){
            line[2] = score;
        } else if(strcmp(sub, "CS") == 0){
            line[3] = score;            
        }
    }
    FILE* fptr = fopen("input.txt", "r");
    int stu, attr, qur;
    fscanf(fptr, "%d %d %d", &stu, &attr, &qur);
    char tmp[20];
    fscanf(fptr, "%s %s %s %s %s %s", tmp, tmp, tmp, tmp, tmp, tmp);
    student *data = (student*)calloc(stu, sizeof(student));
    for(int i=0;i<stu;i++){
        fscanf(fptr, "%s %d %d %d %d %d", data[i].name, &(data[i].student_id), &(data[i].student_grade.Chinese), &(data[i].student_grade.Math), &(data[i].student_grade.English), &(data[i].student_grade.computer_science));
    }
    printf("Results:\n");
    
    printf("Chinese :");
    for(int i=0;i<stu;i++){
        if(data[i].student_grade.Chinese < line[0]){
            printf("%d ", data[i].student_id);
        }
    }
    printf("\n");

    printf("Math :");
    for(int i=0;i<stu;i++){
        if(data[i].student_grade.Math < line[1]){
            printf("%d ", data[i].student_id);
        }
    }
    printf("\n");

    printf("English :");
    for(int i=0;i<stu;i++){
        if(data[i].student_grade.English < line[2]){
            printf("%d ", data[i].student_id);
        }
    }
    printf("\n");

    printf("ComputerScience :");
    for(int i=0;i<stu;i++){
        if(data[i].student_grade.computer_science < line[3]){
            printf("%d ", data[i].student_id);
        }
    }
    printf("\n");

    system("pause");
    return 0;
}

