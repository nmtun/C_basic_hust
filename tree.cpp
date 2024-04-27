#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int id;
	struct Node* leftChild;
	struct Node* rightChild;
}Node;

Node* root;

Node* makeNode(int id){
	Node* p = (Node*)malloc(sizeof(Node));
	p->id = id;
	p->leftChild = NULL;
	p->rightChild = NULL;
	return p;
}

Node* find(Node* r, int id){
	if(r == NULL) return NULL;
	if(r->id == id) return r;
	Node* p = find(r->leftChild,id);
	if(p != NULL) return p;
	return find(r->rightChild,id);
}
void addLeftChild(int u, int left){
	Node* pu = find(root,u);
	if(pu == NULL){
	printf("Not found %d\n",u); return;
	}
	if(pu->leftChild != NULL){
	printf("Node %d has already leftChild\n",u); return;
	}
	if(find(root,left) != NULL){
		printf("already exit\n");
		return;
	}
	pu->leftChild = makeNode(left);
}

void addRightChild(int u, int right){
	Node* pu = find(root,u);
	if(pu == NULL){
	printf("Not found %d\n",u); return;
	}
	if(pu->rightChild != NULL){
	printf("Node %d has already rightChild\n",u); return;
	}
	if(find(root,right) != NULL){
		printf("already exit\n");
		return;
	}
	pu->rightChild = makeNode(right);
}

void load(char* filename){
	FILE* f = fopen(filename,"r");
	root = NULL;
	while(1){
		int u;
		fscanf(f,"%d",&u);
		if(u == -2) break;// termination
		if(root == NULL) root = makeNode(u);// create the root
		int l,r;
		fscanf(f,"%d%d",&l,&r);
		if(l > -1) addLeftChild(u,l);
		if(r > -1) addRightChild(u,r);	
	}	
	fclose(f);
}

void printTree(Node* r){
	if(r == NULL) return;	
	printf("%d: ",r->id);
	if(r->leftChild == NULL) printf("leftChild = NULL");
	else printf("leftChild = %d",r->leftChild->id);
	if(r->rightChild == NULL) printf(", rightChild = NULL");
	else printf(", rightChild = %d",r->rightChild->id);
	printf("\n");
	printTree(r->leftChild);
	printTree(r->rightChild);
}

void printTreeF(Node* r, FILE* f){
	if(r == NULL) return;
	fprintf(f,"%d ",r->id);
	if(r->leftChild == NULL) fprintf(f,"-1 ");
	else fprintf(f,"%d ",r->leftChild->id);
	if(r->rightChild == NULL) fprintf(f,"-1 ");
	else fprintf(f,"%d ",r->rightChild->id);
	fprintf(f,"\n");
	printTreeF(r->leftChild,f);
	printTreeF(r->rightChild,f);
}

void processLoad(){
	char filename[256];
	scanf("%s",filename);
	load(filename);
}
	void printChildren(Node* p){
	if(p->leftChild == NULL) printf(" Node %d does not has leftChild",p->id);
	else printf(", LeftChild = %d",p->leftChild->id);
	if(p->rightChild == NULL) printf(" Node %d does not has rightChild\n",p->id);
	else printf(", RightChild = %d\n",p->rightChild->id);
}

void processFind(){
	int id;
	scanf("%d",&id);	
	Node* p = find(root,id);
	if(p == NULL) printf("Not found %d\n",id);
	else {
	printf("Found node %d: ",id);
	printChildren(p);
	}
}
void processPrint(){
	printTree(root);
}

void processAddLeftChild(){
	int id,u;
	scanf("%d%d",&id,&u);
	addLeftChild(id,u);
}
void processAddRightChild(){
	int id,u;
	scanf("%d %d",&id,&u);
	addRightChild(id,u);
}

int height(Node* p){
	if(p == NULL) return 0;
	int maxH = 0;
	int hl = height(p->leftChild);
	if(maxH < hl) maxH = hl;
	int hr = height(p->rightChild);
	if(maxH < hr) maxH = hr;
	return maxH + 1;
}
void processHeight(){
	int id;
	scanf("%d",&id);
	Node* p = find(root,id);
	if(p == NULL) printf("Not found %d\n",id);
	else printf("Height of %d is %d\n",height(p));
}

int count(Node* p){
	if(p == NULL) return 0;
	return 1 + count(p->leftChild) + count(p->rightChild);
}

int countOdd(Node* r){
	
}


void printLeaves(Node* p){
	if(p == NULL) return;
	if(p->leftChild == NULL && p->rightChild == NULL)
	printf("%d ",p->id);
	printLeaves(p->leftChild);
	printLeaves(p->rightChild);
}
void processFindLeaves(){
	printLeaves(root); printf("\n");
}

void processCount(){
	printf("Number of nodes = %d\n",count(root));
}
void processStore(){
	char filename[256];
	scanf("%s",filename);
	FILE* f = fopen(filename,"w");
	printTreeF(root,f);
	fprintf(f,"-2");
	fclose(f);
}
void freeTree(Node* r){
	if(r == NULL) return;
	freeTree(r->leftChild);
	freeTree(r->rightChild);
	free(r); r = NULL;
}

int main(){
	while(1){
		char cmd[256]; // representing the input command
		printf("Enter a command: ");
		scanf("%s",cmd);
		if(strcmp(cmd,"Quit") == 0) break;
		else if(strcmp(cmd,"Load")==0) processLoad();
		else if(strcmp(cmd,"Print")==0) processPrint();
		else if(strcmp(cmd,"Find")==0) processFind();
		else if(strcmp(cmd,"Height")==0) processHeight();
		else if(strcmp(cmd,"Count")==0) processCount();
		else if(strcmp(cmd,"FindLeaves")==0) processFindLeaves();
		else if(strcmp(cmd,"AddLeftChild")==0) processAddLeftChild();
		else if(strcmp(cmd,"AddRightChild")==0) processAddRightChild();
		else if(strcmp(cmd,"Store")== 0) processStore();
	}
	freeTree(root);
	return 0;
}



