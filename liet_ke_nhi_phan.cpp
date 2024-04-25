#include <stdio.h>

void xuat(int a[], int n){
	for(int i=0; i<n; i++){
		printf("%d",a[i]);
	}
	printf("\n");
}

int check(int a[], int k){
	if(k>=1 && a[k-1]==1 && a[k]==1){
		return 0;
	}
	return 1;
}

void sinh(int a[], int n, int k){
	if(k==n){
		xuat(a,n);
		return;
	}
	for(int i=0; i<=1; i++){
		a[k]=i;
		if(check(a,k)){
		sinh(a,n,k+1);
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	sinh(a,n,0);
	return 0;
}
