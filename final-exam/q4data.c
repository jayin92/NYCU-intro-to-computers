#include <stdlib.h>
#include <time.h>
#include "q5data.h"


#define MAXN 10
#define RAND_RANGE 100


node* data_a(){
  node* head = NULL, *tail = NULL;
  srand(time(NULL));
  int length = (rand() % MAXN) + 1, num = rand() % RAND_RANGE;
  for(int i = 0; i < length; i++){
    if(head == NULL)
      head = (node*)malloc(sizeof(node)), tail = head;
    else{
      tail -> next = (node*)malloc(sizeof(node));
      tail = tail -> next;
    }
    tail -> number = num;
    tail -> next = NULL;
    num += (rand() % RAND_RANGE) + 1;
  }
  return head;
};

node* data_b(){
  node* head = NULL, *tail = NULL;
  int length = (rand() % MAXN) + 1, num = rand() % RAND_RANGE;
  for(int i = 0; i < length; i++){
    if(head == NULL)
      head = (node*)malloc(sizeof(node)), tail = head;
    else{
      tail -> next = (node*)malloc(sizeof(node));
      tail = tail -> next;
    }
    tail -> number = num;
    tail -> next = NULL;
    num += (rand() % RAND_RANGE) + 1;
  }
  return head;
};
