#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>

/**
最小编辑代价
https://www.nowcoder.com/practice/dfa502cf6a914fb5b98c59c56619e96c?tpId=101&tqId=33111&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    string s1,s2;
    cin>>s1>>s2;
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int m=s1.size(),n=s2.size();
    int** dp=(int**)malloc(sizeof(int*)*(m+1));
    for(int i=0; i<m+1; i++)
        dp[i]=(int*)malloc(sizeof(int)*(n+1));
    for(int j=0; j<n+1; j++)
        dp[0][j]=a*j;
    for(int i=0; i<m+1; i++)
        dp[i][0]=b*i;
    for(int i=1; i<m+1; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=dp[i-1][j-1]+c;
            dp[i][j]=min(dp[i][j],min(b+dp[i-1][j],dp[i][j-1]+a));
        }
    }
    printf("%d\n",dp[m][n]);
    return 0;
}
