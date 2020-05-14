#include<stdio.h>
#include<iostream>
#include<string>

/**
字符串中数字子串的求和
**/

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    string s;
    cin>>s;
    int sum=0;
    int cur=0;
    int pos=1;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='-')
        {
            pos*=-1;
        }
        else if(s[i]<='9'&&s[i]>='0')
        {
            cur=cur*10+s[i]-'0';
            if(i==s.size()-1||!(s[i+1]<='9'&&s[i+1]>='0'))
            {
                sum+=pos*cur;
                cur=0;
                pos=1;
            }
        }
        else
        {
            if(i==s.size()-1||s[i+1]!='-')
                pos=1;
        }
    }
    printf("%d\n",sum);
    return 0;
}
