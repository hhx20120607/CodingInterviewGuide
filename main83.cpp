#include<stdio.h>
#include<stdlib.h>

int main(){
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int cand,time=0;
    for(int i=0;i<n;i++){
        if(arr[i]==cand)
            time++;
        else if(time==0)
            cand=arr[i];
        else
            time--;
    }
    time=0;
    for(int i=0;i<n;i++){
        if(arr[i]==cand)
            time++;
    }
    if(time>n/2)
        printf("%d\n",cand);
    else
        printf("-1\n");
    return 0;
}
