#include<stdio.h>
#include<stdlib.h>

int main(){
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    if(n==1){
        printf("0\n");
        return 0;
    }
    int i=0,j=n-1;
    while(i<j){
        int m=(i+j)/2;
        if(arr[m]>arr[m-1])
            j=m-1;
        else if(arr[m]>arr[m+1])
            i=m+1;
        else{
            printf("%d\n",m);
            return 0;
        }
    }
    printf("%d\n",i);
    return 0;
}
