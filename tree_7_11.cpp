#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
	int id;
	char name[128];
	char school[128];
	struct Node* leftChild;
	struct Node* rightChild;
}Node;

Node* makeNode(int id, char* name, char* school){
	Node* p = (Node*)malloc(sizeof(Node));
	p->id = id;
	strcpy(p->name,name);
	strcpy(p->school,school);
	return p;
}

Node* readLine(char* line){
	printf("%s",line);
	return makeNode(-1, NULL, NULL);
}

int main(){
	int n; scanf("%d",&n);
	int i=0;
	while(i<n){
		char* line;
		scanf("%s",line);
		i++;
	}
	return 0;
}
