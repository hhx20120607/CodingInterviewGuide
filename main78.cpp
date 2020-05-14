#include<stdio.h>
#include<stdlib.h>

int main(){
    freopen("data.in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int** arr=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)
        arr[i]=(int*)malloc(sizeof(int)*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            scanf("%d",&arr[i][j]);
    }
    int i=1,j=-1;
    int d=1;
    int k=0,s=n*m;
    while(k<s){
        if(d==1){
            if(i-1>=0&&j+1<=m-1){
                i--;
                j++;
            }
            else{
                if(j+1<=m-1)
                    j++;
                else
                    i++;
                d=2;
            }
        }
        else{
            if(i+1<=n-1&&j-1>=0){
                i++;
                j--;
            }
            else{
                if(i+1<=n-1)
                    i++;
                else
                    j++;
                d=1;
            }
        }
        printf("%d ",arr[i][j]);
        k++;
    }
    return 0;
}
