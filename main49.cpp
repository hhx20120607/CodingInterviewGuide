#include<stdio.h>
#include<iostream>
#include<string>

/**
ÅÐ¶ÏÁ½¸ö×Ö·û´®ÊÇ·ñ»¥ÎªÐý×ª´Ê
https://www.nowcoder.com/practice/687deda2cc57473499e058207f6258cf?tpId=101&tqId=33164&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/
using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    int m,n;
    scanf("%d%d",&m,&n);
    string s1,s2;
    cin>>s1>>s2;
    if(m!=n)
    {
        printf("NO\n");
        return 0;
    }
    string s3=s1+s1;
    int t=s3.find(s2);
    if(s3.find(s2)!=-1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
