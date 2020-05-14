#include <stdio.h>
#include <string>
#include <iostream>

/**最长公共子串
https://www.nowcoder.com/practice/210741385d37490c97446aa50874e62d?tpId=101&tqId=33101&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    string s1,s2;
    cin>>s1>>s2;
    int p=-1,q=-1;
    int res=0;
    int i=0,j=0;
    for(j=0; j<s2.size(); j++)
    {
        int t=s1[i]==s2[j]?1:0;
        if(t>res)
        {
            res=t;
            p=i;
            q=j;
        }
        int k=1;
        while(i+k<s1.size()&&j+k<s2.size())
        {
            t=s1[i+k]==s2[j+k]?t+1:0;
            if(t>res)
            {
                res=t;
                p=i+k;
                q=j+k;
            }
            k++;
        }
    }
    i=0;
    j=0;
    for(i=0; i<s1.size(); i++)
    {
        int t=s1[i]==s2[j]?1:0;
        if(t>res)
        {
            res=t;
            p=i;
            q=j;
        }
        int k=1;
        while(i+k<s1.size()&&j+k<s2.size())
        {
            t=s1[i+k]==s2[j+k]?t+1:0;
            if(t>res)
            {
                res=t;
                p=i+k;
                q=j+k;
            }
            k++;
        }
    }
    if(res==0)
        printf("-1\n");
    else{
        for(i=p+1-res;i<=p;i++)
            printf("%c",s1[i]);
        printf("\n");
    }
    return 0;
}
