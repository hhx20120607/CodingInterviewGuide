#include<stdio.h>
#include<string.h>
#define maxn 100000+1

/**
翻转字符串
https://www.nowcoder.com/practice/972117dd8f334076a5df6a68b0a8f3dd?tpId=101&tqId=33184&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
https://www.nowcoder.com/practice/79c562297c0e4ff0952ef39ecde1bd6b?tpId=101&tqId=33185&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/


char s[maxn];

void fun1()
{
    int i=0;
    int c=-1;
    while((c=getc(stdin))!='\n')
    {
        s[i++]=c;
    }
    s[i]='\0';
    int p,q;
    for(int j=0; j<i; j++)
    {
        if(j==0||s[j-1]==' ')
            p=j;
        if(j==i-1||s[j+1]==' ')
        {
            q=j;
            for(int k=p; k<=(q+p)/2; k++)
            {
                char t=s[k];
                s[k]=s[q+p-k];
                s[q+p-k]=t;
            }
        }
    }
    printf("%s",s);
}

void reverse(char* s,int p,int q)
{
    for(int k=p; k<=(q+p)/2; k++)
    {
        char t=s[k];
        s[k]=s[q+p-k];
        s[q+p-k]=t;
    }
}

void fun2()
{
    int n;
    scanf("%d",&n);
    getc(stdin);
    int i=0;
    int c=-1;
    while((c=getc(stdin))!='\n')
    {
        s[i++]=c;
    }
    s[i]='\0';
    reverse(s,0,n-1);
    reverse(s,n,strlen(s)-1);
    reverse(s,0,strlen(s)-1);
    printf("%s",s);
}

int main()
{
    freopen("data.in","r",stdin);
    fun2();
    return 0;
}
