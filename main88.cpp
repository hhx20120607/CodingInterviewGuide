#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long long mergeSort(int* arr,int l,int r){
    if(l==r)
        return 0;
    int m=(l+r)/2;
    long long a=mergeSort(arr,l,m);
    long long b=mergeSort(arr,m+1,r);
    long long c=0;
    int* temp=(int*)malloc(sizeof(int)*(r-l+1));
    int i=l,j=m+1,k=0;
    while(i<=m&&j<=r){
        if(arr[i]<=arr[j]){
            c+=(r-j+1)*arr[i];
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=m)
        temp[k++]=arr[i++];
    while(j<=r)
        temp[k++]=arr[j++];
    memcpy(arr+l,temp,sizeof(int)*(r-l+1));
    free(temp);
    return c+a+b;
}

int main(){
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("%lld\n",mergeSort(arr,0,n-1));
    return 0;
}
