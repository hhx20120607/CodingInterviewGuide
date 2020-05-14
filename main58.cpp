#include<iostream>
#include<string>
#include<string.h>

/**
添加最少字符使字符串整体都是回文字符串
https://www.nowcoder.com/practice/a5849b7e3bc940ff8c97b47d3f76199b?tpId=101&tqId=33192&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
https://www.nowcoder.com/practice/239d332c9eb741ae9e41d32b40684530?tpId=101&tqId=33193&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

void fun1()
{
    string s;
    cin>>s;
    int n=s.size();
    int** dp=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
        dp[i]=(int*)malloc(sizeof(int)*n);
    for(int j=0; j<n; j++)
    {
        for(int i=j; i>=0; i--)
        {
            if(i==j)
                dp[i][j]=0;
            else if(i+1==j)
                dp[i][j]=s[i]==s[j]?0:1;
            else if(s[i]==s[j])
                dp[i][j]=dp[i+1][j-1];
            else
                dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
        }
    }
    char* d=(char*)malloc(sizeof(char)*(dp[0][n-1]+n+1));
    int i=0,j=n-1;
    int p=0,q=dp[0][n-1]+n-1;
    d[q+1]='\0';
    while(i<=j)
    {
        if(s[i]==s[j])
        {
            d[p++]=s[i];
            d[q--]=s[j];
            i++;
            j--;
        }
        else if(dp[i][j]==dp[i+1][j]+1)
        {
            d[p++]=s[i];
            d[q--]=s[i];
            i++;
        }
        else
        {
            d[p++]=s[j];
            d[q--]=s[j];
            j--;
        }
    }
    printf("%s\n",d);
}

void fun2()
{
    string s1,s2;
    cin>>s1>>s2;
    char* arr=(char*)malloc(sizeof(char)*(2*s1.size()-s2.size()+1));
    arr[2*s1.size()-s2.size()]='\0';
    int p=0,q=2*s1.size()-s2.size()-1;
    int a=0,b=s1.size()-1;
    int c=0,d=s2.size()-1;
    while(a<=b)
    {
        int i=a;
        while(s1[i]!=s2[c])
            i++;
        int j=b;
        while(s1[j]!=s2[d])
            j--;
        int k=a;
        while(k<i)
        {
            arr[p++]=s1[k++];
        }
        k=b;
        while(k>j)
        {
            arr[p++]=s1[k--];
        }
        k=a;
        while(k<i)
        {
            arr[q--]=s1[k++];
        }
        k=b;
        while(k>j)
        {
            arr[q--]=s1[k--];
        }
        arr[p++]=s2[c];
        arr[q--]=s2[d];
        a=i+1;
        b=j-1;
        c++;
        d--;
    }
    printf("%s\n",arr);
}

int main()
{
    freopen("data.in","r",stdin);
    fun2();
    return 0;
}
