#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int so_con[n];
    int chi_so1[n], chi_so2[n];
    char con[n][50];  //1ptu la mang 1 chieu` co the lu toi da 49 ki tu trong ten;
    char cha[n][50];  //
    for (int i = 0; i < n; i++) {
        scanf("%d",&chi_so1[i]);
        scanf("%d",&chi_so2[i]);
		scanf("%s", cha[i]);
        scanf("%d", &so_con[i]);
        for (int j = 0; j < so_con[i]; j++) {
            scanf("%s", con[j]);  //chi can` luu vao mang 1 chieu` con[j]  
        }
    }
    int ans = 0;
    char cmp[50];  
    strcpy(cmp, cha[0]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < so_con[i]; j++) {
            int k = strcmp(cmp, con[j]);  
            if (k == 0) ans++;
        }
    }
    printf("%d", ans);
    return 0;
}

