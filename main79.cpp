#include<stdio.h>
#include<stdlib.h>

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int minA,maxA;
    int p=-1,q=-1;
    for(int i=0;i<n;i++){
        if(i==0){
            maxA=arr[i];
        }
        else{
            if(arr[i]<maxA)
                p=i;
            else
                maxA=arr[i];
        }
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            minA=arr[i];
        }
        else {
            if(arr[i]>minA)
                q=i;
            else
                minA=arr[i];
        }
    }
    if(p==-1||q==-1)
        printf("0\n");
    else
        printf("%d\n",p-q+1);
    return 0;
}
