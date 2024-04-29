#include <stdio.h>

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	int arr[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int ans=0;
	for(int i=0; i<m; i++){
		int check = 1;
		for(int j=0; j<n; j++){
			if(arr[j][i] == 0){
				check = 0;
				break;	
			}
		}
		ans+=check;
	}
	printf("%d", ans);
	return 0;
}


