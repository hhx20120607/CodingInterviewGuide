#include<stdio.h>
#include<iostream>
#include<string>

/**
字符串的交错组成
https://www.nowcoder.com/practice/1fdefa4178f7460d93738b28441e1277?tpId=101&tqId=33112&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

int main(){
    freopen("data.in","r",stdin);
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int m=s1.size(),n=s2.size();
    if(s3.size()!=m+n){
        printf("NO\n");
        return 0;
    }
    bool** dp=(bool**)malloc(sizeof(bool*)*(m+1));
    for(int i=0;i<m+1;i++)
        dp[i]=(bool*)malloc(sizeof(bool)*(n+1));
    dp[0][0]=true;
    for(int j=1;j<n+1;j++){
        if(s2[j-1]==s3[j-1]&&dp[0][j-1])
            dp[0][j]=true;
        else
            dp[0][j]=false;
    }
    for(int i=1;i<m+1;i++){
        if(s1[i-1]==s3[i-1]&&dp[i-1][0])
            dp[i][0]=true;
        else
            dp[i][0]=false;
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(s3[i+j-1]==s1[i-1]&&dp[i-1][j] || s3[i+j-1]==s2[j-1]&&dp[i][j-1])
                dp[i][j]=true;
            else
                dp[i][j]=false;
        }
    }
    if(dp[m][n]==true)
        printf("YES\n");
    else
        printf("NO\n");
}
