#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
换钱的方法数
https://www.nowcoder.com/practice/39cb6c6e2b844a8cba382c8e26951e0a?tpId=101&tqId=33087&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

int main()
{
    freopen("data.in","r",stdin);
    long long maxn=(int)(1e9+7);
    int n,m;
    scanf("%d%d",&n,&m);
    int* arr=(int*)malloc(sizeof(int)*(n));
    int* dp=(int*)malloc(sizeof(int)*(m+1));
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    memset(dp,0,sizeof(int)*(m+1));
    int k=0;
    while(k*arr[0]<=m)
    {
        dp[k*arr[0]]=1;
        k++;
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m+1; j++)
        {
            if(j-arr[i]>=0)
                dp[j]=(dp[j]+dp[j-arr[i]])%maxn;
        }
    }
    printf("%d\n",dp[m]%maxn);
}
