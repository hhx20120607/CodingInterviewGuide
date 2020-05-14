#include<stdio.h>
#include<limits.h>
#include<stdlib.h>


int main(){
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int* dp=(int*)malloc(sizeof(int)*n);
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--){
        dp[i]=INT_MAX;
        for(int j=1;j<=arr[i];j++){
            if(i+j<n&&dp[i+j]+1<dp[i])
                dp[i]=dp[i+j]+1;
        }
    }
    printf("%d\n",dp[0]);
    return 0;
}
