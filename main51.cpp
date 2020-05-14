#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

/**
替换字符串中连续出现的指定字符串
**/

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int i=0;
    int index=-1;
    vector<int> v;
    while((index=s1.find(s2,i))!=-1)
    {
        v.push_back(index);
        i=index+s2.size();
    }
    string d;
    if(!v.empty())
    {
        for(int j=0; j<v[0]; j++)
            d.push_back(s1[j]);
    }
    else
    {
        cout<<s1;
        return 0;
    }
    for(int k=0; k<v.size(); k++)
    {
        if(k==v.size()-1||v[k]+s2.size()!=v[k+1])
        {
            d+=s3;
        }
    }
    cout<<d;
    return 0;
}
