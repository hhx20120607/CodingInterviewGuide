#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<algorithm>

/**
龙与地下城游戏
https://www.nowcoder.com/practice/c0ca4c9e65144af69ada03febaa0e33a?tpId=101&tqId=33113&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int** arr=(int**)malloc(sizeof(int*)*n);
    int** dp=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        arr[i]=(int*)malloc(sizeof(int)*m);
        dp[i]=(int*)malloc(sizeof(int)*m);
        for(int j=0; j<m; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    dp[n-1][m-1]=max(1,1-arr[n-1][m-1]);
    for(int j=m-2;j>=0;j--)
        dp[n-1][j]=max(1,dp[n-1][j+1]-arr[n-1][j]);
    for(int i=n-2;i>=0;i--)
        dp[i][m-1]=max(1,dp[i+1][m-1]-arr[i][m-1]);
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            dp[i][j]=min(max(dp[i+1][j]-arr[i][j],1),max(dp[i][j+1]-arr[i][j],1));
        }
    }
    printf("%d\n",dp[0][0]);
    return 0;
}
