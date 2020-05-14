#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

/**
最长公共子序列
https://www.nowcoder.com/practice/4727c06b9ee9446cab2e859b4bb86bb8?tpId=101&tqId=33099&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;


int main()
{
    freopen("data.in","r",stdin);
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.size(),n=s2.size();
    int** dp=(int**)malloc(sizeof(int*)*m);
    for(int i=0; i<m; i++)
        dp[i]=(int*)malloc(sizeof(int)*n);
    dp[0][0]=s1[0]==s2[0]?1:0;
    for(int i=1; i<n; i++)
        dp[0][i]=s1[0]==s2[i]?1:dp[0][i-1];
    for(int j=1; j<m; j++)
        dp[j][0]=s1[j]==s2[0]?1:dp[j-1][0];
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=s1[i]==s2[j]?dp[i-1][j-1]+1:dp[i-1][j-1];
            dp[i][j]=max(dp[i][j],max(dp[i][j-1],dp[i-1][j]));
        }
    }
    char* ans=(char*)malloc(sizeof(char)*(dp[m-1][n-1]+1));
    int p=m-1,q=n-1;
    int k=dp[m-1][n-1]-1;
    while(k>=0){
        if(p>=1&&dp[p][q]==dp[p-1][q]){
                p--;
        }
        else if(q>=1&&dp[p][q]==dp[p][q-1]){
            q--;
        }
        else{
            ans[k--]=s1[p];
            p--;
            q--;
        }
    }
    ans[dp[m-1][n-1]]='\0';
    printf("%s\n",ans);
    free(ans);
    for(int i=0;i<m;i++)
        free(dp[i]);
    free(dp);
    return 0;
}
