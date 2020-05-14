#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>

/**
表达式得到期望结果的组成种数
https://www.nowcoder.com/practice/9690bd908d5b4f9b91640fa835ef6f4f?tpId=101&tqId=33115&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

int main()
{
    long long maxn=1e9+7;
    freopen("data.in","r",stdin);
    string s;
    cin>>s;
    int n=s.size();
    long long** dp1=(long long**)malloc(sizeof(long long*)*n);
    long long** dp2=(long long**)malloc(sizeof(long long*)*n);
    for(int i=0; i<n; i++)
    {
        dp1[i]=(long long*)malloc(sizeof(long long)*n);
        memset(dp1[i],0,sizeof(long long)*n);

    }
    for(int i=0; i<n; i++)
    {
        dp2[i]=(long long*)malloc(sizeof(long long)*n);
        memset(dp2[i],0,sizeof(long long)*n);

    }
    string t;
    cin>>t;
    bool desired=strcmp(t.c_str(),"true")?false:true;
    int ok=1;
    for(int i=0; i<n; i++)
    {
        if(i%2==0&&s[i]!='0'&&s[i]!='1')
        {
            ok=0;
            break;
        }
        if(i%2==1&&s[i]!='^'&&s[i]!='&'&&s[i]!='|')
        {
            ok=0;
            break;
        }
    }
    if(s.size()%2!=1)
        ok=0;
    if(!ok)
    {
        printf("0\n");
        return 0;
    }
    for(int i=0; i<n; i+=2)
    {
        dp1[i][i]=s[i]=='0'?0:1;
        dp2[i][i]=s[i]=='0'?1:0;
    }
    for(int j=2; j<n; j+=2)
    {
        for(int i=j-2; i>=0; i-=2)
        {
            for(int k=i; k<j; k+=2)
            {
                if(s[k+1]=='&')
                {
                    dp1[i][j]+=dp1[i][k]*dp1[k+2][j];
                    dp2[i][j]+=(dp1[i][k]*dp2[k+2][j]+dp2[i][k]*dp1[k+2][j]+dp2[i][k]*dp2[k+2][j]);
                }
                else if(s[k+1]=='|')
                {
                    dp1[i][j]+=(dp1[i][k]*dp1[k+2][j]+dp1[i][k]*dp2[k+2][j]+dp2[i][k]*dp1[k+2][j]);
                    dp2[i][j]+=dp2[i][k]*dp2[k+2][j];
                }
                else
                {
                    dp1[i][j]+=(dp1[i][k]*dp2[k+2][j]+dp2[i][k]*dp1[k+2][j]);
                    dp2[i][j]+=(dp1[i][k]*dp1[k+2][j]+dp2[i][k]*dp2[k+2][j]);
                }
                dp1[i][j]=dp1[i][j]%maxn;
                dp2[i][j]=dp2[i][j]%maxn;

            }
        }
    }
    if(desired)
        printf("%lld\n",dp1[0][n-1]);
    else
        printf("%lld\n",dp2[0][n-1]);
    return 0;
}
