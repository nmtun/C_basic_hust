#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// typedef struct sinhvien{
//     char name[30];
//     char lop[10];
//     double gpa;
// }sinhvien;

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* makeNode(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL; 
    return newNode;
}

void duyet(Node* head){
   while(head != NULL){
    printf("%d ",head->data);
    head = head->next;
   }
}

void pushFront(Node** head, int x){ //them node vao dau ds
    Node *newNode = makeNode(x);
    newNode->next = *head;
    *head = newNode;
}

void pushBack(Node** head, int x){ // them node vao cuoi ds
    Node* temp = *head;
    Node* newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

int main(){
    Node* head=NULL;
    for(int i=1; i<=5; i++){
        pushBack(&head,i);
        pushFront(&head,i);
    }
    duyet(head);
    return 0;
}