#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

/**
数组中两个字符串的最小距离
https://www.nowcoder.com/practice/2c6a0a8e1d20492f92941400036e0890?tpId=101&tqId=33190&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

void fun1()
{
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    vector<string> v1;
    for(int i=0; i<n; i++)
    {
        string t;
        cin>>t;
        v1.push_back(t);
    }
    int last=-1;
    int ans=INT_MAX;
    for(int i=0; i<n; i++)
    {
        if(v1[i]==s1||v1[i]==s2)
        {
            if(last==-1)
            {
                last=i;
                continue;
            }
            if(v1[last]==v1[i])
                last=i;
            else
            {
                if(i-last<ans)
                    ans=i-last;
                last=i;
            }
        }
    }
    if(ans==INT_MAX)
        printf("%d\n",-1);
    else
        printf("%d\n",ans);
}

map<string,map<string,int>> map1;
map<string,int> map2;

void fun2()
{
    int n;
    cin>>n;
    vector<string> v1;
    for(int i=0; i<n; i++)
    {
        string t;
        cin>>t;
        v1.push_back(t);
    }
    for(int i=0; i<n; i++)
    {
        map2[v1[i]]=i;
        for(int j=0; j<n; j++)
        {
            if(j!=i&&map2.find(v1[j])!=map2.end())
            {
                if(map1.find(v1[j])==map1.end()||map1[v1[j]].find(v1[i])==map1[v1[j]].end()||map1[v1[j]][v1[i]]>i-map2[v1[j]])
                    map1[v1[j]][v1[i]]=i-map2[v1[j]];
            }
        }
    }
    string s1,s2;
    cin>>s1>>s2;
    if(map2.find(s1)==map2.end()||map2.find(s2)==map2.end())
        printf("-1\n");
    else
    {
        int ans=INT_MAX;
        if(map1.find(s1)!=map1.end()&&map1[s1].find(s2)!=map1[s1].end()&&map1[s1][s2]<ans)
            ans=map1[s1][s2];
        if(map1.find(s2)!=map1.end()&&map1[s2].find(s1)!=map1[s2].end()&&map1[s2][s1]<ans)
            ans=map1[s2][s1];
        printf("%d\n",ans);
    }
}

int main()
{
    freopen("data.in","r",stdin);
    fun2();
    return 0;
}
