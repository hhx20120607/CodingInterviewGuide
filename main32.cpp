#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>

/**
换钱的最小货币数
https://www.nowcoder.com/practice/4e05294fc5aa4d4fa8eacef2e606e5a8?tpId=101&tqId=33080&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int* arr=(int*)malloc(sizeof(int)*n);
    int* dp=(int*)malloc(sizeof(int)*(m+1));
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    for(int i=0; i<=m; i++)
        dp[i]=INT_MAX;
    int k=0;
    while(k*arr[0]<=m)
    {
        dp[k*arr[0]]=k;
        k++;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(j-arr[i]>=0&&dp[j-arr[i]]!=INT_MAX&&dp[j]>dp[j-arr[i]]+1)
                dp[j]=dp[j-arr[i]]+1;
        }
    }
    if(dp[m]!=INT_MAX)
        printf("%d\n",dp[m]);
    else
        printf("-1\n");
    return 0;
}
