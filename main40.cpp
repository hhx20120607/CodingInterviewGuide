#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>

/**
数字字符串转换为字母组合的种数
https://www.nowcoder.com/practice/6a5d7615332c49eb810c374dd6f37857?tpId=101&tqId=33114&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    int maxn=1e9+7;
    string s;
    cin>>s;
    int* dp=(int*)malloc(sizeof(int)*(s.size()+1));
    memset(dp,0,sizeof(int)*(s.size()+1));
    dp[0]=1;
    for(int i=1; i<=s.size(); i++)
    {
        if(s[i-1]!='0')
            dp[i]=(dp[i]%maxn+dp[i-1]%maxn)%maxn;
        if(i>=2&&s[i-2]!='0')
        {
            int c=(s[i-2]-'0')*10+s[i-1]-'0';
            if(c>=1&&c<=26)
                dp[i]=(dp[i]%maxn+dp[i-2]%maxn)%maxn;
        }
    }
    printf("%d\n",dp[s.size()]);
    return 0;
}
