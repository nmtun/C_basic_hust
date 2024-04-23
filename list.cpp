#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* next;
};
typedef struct node node;
node* makeNode(int x){
	node* newNode =(node*)malloc(sizeof(node));
	newNode->data=x;
	newNode->next=NULL;
	return newNode;
}
int size(node *head){
	int dem = 0;
	while(head != NULL){
		++dem;
		head=head->next;
	}
	return dem;
}
void duyet(node* head){
	while(head != NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
int kiemtra(node *head,int x){
	node *p = head;
	while(p!=NULL){
		if(p->data==x)return 0;
		p=p->next;
	}
	return 1;
	
}
void themdau(node **head,int x){
	node *newNode = makeNode(x);
	newNode->next=*head;
	*head= newNode;
}
void themcuoi(node **head,int x){
	node *newNode = makeNode(x);
	node *tmp= *head;
	if(*head == NULL){
		*head = newNode;
		return;
	}
	while(tmp->next != NULL){
		tmp = tmp -> next;
	}
	tmp->next= newNode;
}
void themgiua(node **head,int x,int k){
	node *newNode = makeNode(x);
	node* p =*head;
	int dem=0;
	while(p->data != k){
		dem++;
		p=p->next;
	}                                                                     
	int n=size(*head);
	if(dem==0){
		themdau(head,x);
		return ;
	}
	node *tmp = *head;
	for(int i=0;i<dem;i++){
		tmp=tmp->next;
	}
	newNode->next = tmp -> next;
	tmp->next = newNode;
}
void themgiua2(node **head,int x,int k){
	node *newNode = makeNode(x);
	node* p =*head;
	int dem=0;
	while(p->data != k){
		dem++;
		p=p->next;
	}                                                                     
	int n=size(*head);
	if(dem==0){
		themdau(head,x);
		return ;
	}
	node *tmp = *head;
	for(int i=0;i<dem-1;i++){
		tmp=tmp->next;
	}
	newNode->next = tmp -> next;
	tmp->next = newNode;
}
void xoadau(node **head){
	if(*head == NULL)return ;
	node *tmp = *head;
	*head = (*head)->next;
	delete tmp;
}
void xoacuoi(node **head){
	if(*head==NULL)return;
	node *tmp = *head;
	if(tmp->next==NULL){
		*head = NULL;
		delete tmp;
		return;
	}
	while(tmp->next->next != NULL){
		tmp = tmp->next;
	}
	node* last= tmp->next;
	tmp->next=NULL;
	delete tmp;
}
void xoagiua(node **head, int k){
	if(kiemtra(*head,k)==1)return;
	else{
	
	node* p = *head;
	int dem = 0;
	while(p->data != k){
		dem++;
		p=p->next;
	}
	int n = size(*head);
	if(dem == 0) xoadau(head);
	else{
		node *temp = *head;
		for(int i = 1; i <= dem -1; i++){
			temp = temp->next;
		}
		//temp : k - 1
		node *kth = temp->next; // node thu k
		//cho k-1 => ket noi voi node thu k + 1
		temp->next = kth->next;
		delete kth; // free(kth)
	}
}
}
node* daonguoc(node* head) {
    node* prev = nullptr;
    node* current = head;
    node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


int main(){
	int n;
	cin>>n;
	node *head=NULL;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		themcuoi(&head,x);
	}
	while(1){
		char ch[100000];
		cin>>ch;
		if(strcmp(ch,"#")==0)break;
		if(strcmp(ch,"addlast")==0){
			int n;
			cin>>n;
			if(kiemtra(head,n))themcuoi(&head,n);
		}
		if(strcmp(ch,"addfirst")==0){
			int n;cin>>n;
			if(kiemtra(head,n))themdau(&head,n);
		}
		if(strcmp(ch,"addafter")==0){
			int n,k;
			cin>>n>>k;
			if(kiemtra(head,n))themgiua(&head,n,k);
		}
		if(strcmp(ch,"remove")==0){
			int n;
			cin>>n;
			xoagiua(&head,n);
		}
		if(strcmp(ch,"addbefore")==0){
			int n,k;
			cin>>n>>k;
			if(kiemtra(head,n))themgiua2(&head,n,k);
		}
		if(strcmp(ch,"reverse")==0){
		  head=daonguoc(head);
		}
	}
		
	duyet(head);
}

