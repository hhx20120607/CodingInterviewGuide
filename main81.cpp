#include<stdio.h>
#include<stdlib.h>

int main(){
    freopen("data.in","r",stdin);
    int m,n,k;
    scanf("%d%d%d",&m,&n,&k);
    int** arr=(int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++)
        arr[i]=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    }
    int i=m-1,j=0;
    int ok=0;
    while(i>=0&&j<=n-1){
        if(arr[i][j]==k){
            ok=1;
            break;
        }
        else if(arr[i][j]>k){
            i--;
        }
        else{
            j++;
        }
    }
    if(ok)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
