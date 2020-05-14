#include<iostream>
#include<string>
#include<map>

/**
括号字符串得有效性和最长有效长度
https://www.nowcoder.com/practice/769abd985f3849d0b9415b082f94c192?tpId=101&tqId=33194&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
https://www.nowcoder.com/practice/335acafb6d5141b7873c4b0f24d53c57?tpId=101&tqId=33195&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

void fun1()
{
    string s;
    cin>>s;
    int j=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
            j++;
        else if(s[i]==')')
        {
            if(j>0)
                j--;
            else
            {
                printf("NO\n");
                return;
            }
        }
        else
        {
            printf("NO\n");
            return;
        }
    }
    if(j==0)
        printf("YES\n");
    else
        printf("NO\n");
}

void fun2()
{
    string s;
    cin>>s;
    int n=s.size();
    int* dp=(int*)malloc(sizeof(int)*n);
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]==')')
        {
            int j=i-1-dp[i-1];
            if(s[j]=='(')
            {
                if(j-1>=0)
                    dp[i]=dp[i-1]+2+dp[j-1];
                else
                    dp[i]=dp[i-1]+2;
            }
            else
                dp[i]=0;
        }
        else
            dp[i]=0;
        if(dp[i]>ans)
            ans=dp[i];
    }
    printf("%d\n",ans);
}

int main()
{
    freopen("data.in","r",stdin);
    return 0;
}
