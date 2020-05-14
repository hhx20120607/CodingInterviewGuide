#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    long long maxn=pow(2,29);
    int n;
    scanf("%d",&n);
    long long* dp=(long long*)malloc(sizeof(long long)*n);
    dp[n-1]=1;
    dp[n-2]=2;
    for(int i=n-3;i>=0;i--)
        dp[i]=(dp[i+1]%maxn+dp[i+2]%maxn)%maxn;
    printf("%lld\n",dp[0]);
    return 0;
}
