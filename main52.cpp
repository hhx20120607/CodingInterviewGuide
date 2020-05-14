#include<stdio.h>
#include<iostream>
#include<string>

/**
字符串的统计字符串
https://www.nowcoder.com/practice/e8b97a6d64ae4304b6f0ff4ecae1589d?tpId=101&tqId=33166&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    string s;
    cin>>s;
    int start=1;
    int p,q;
    for(int i=0;i<s.size();i++){
        if(i==0||s[i]!=s[i-1])
            p=i;
        if(i==s.size()-1||s[i]!=s[i+1]){
            q=i;
            if(!start)
                printf("_");
            else
                start=0;
            printf("%c_%d",s[p],q-p+1);
        }
    }
    return 0;
}
