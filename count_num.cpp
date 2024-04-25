#include <stdio.h>

int main(){
	long int n,q;
	scanf("%ld %ld", &n, &q);
	int arr[n];
	for(int i=0; i<n; i++){
		scanf("%ld", &arr[i]);
	}
	int ans=0;
	int a[n]={0};
	for(int i=0; i<n; i++){
		int check=q-arr[i];
			if(check>=0 && a[check]==1){
				ans++;
			}
		a[arr[i]]=1;
	
	}
	printf("%d", ans);
	return 0;
}
