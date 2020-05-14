#include<stdio.h>
#include<stdlib.h>

int main(){
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int** arr=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)
        arr[i]=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            printf("%d",arr[j][i]);
            if(j!=0)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}
