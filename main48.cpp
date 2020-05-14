#include<stdio.h>
#include<iostream>
#include<string>

/**
去掉字符串中连续出现的k个0的子串
**/

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    string s,d;
    cin>>s;
    int n;
    scanf("%d",&n);
    int p,q;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]!='0')
            d.push_back(s[i]);
        if(s[i]!='0'&&i!=s.size()-1&&s[i+1]=='0')
            p=i+1;
        if(s[i]=='0'&&(i==s.size()-1||s[i+1]!='0'))
        {
            q=i;
            if(q-p+1!=n)
            {
                for(int k=p; k<=q; k++)
                {
                    d.push_back('0');
                }
            }
        }
    }
    cout<<d;
    return 0;
}
