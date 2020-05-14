#include<stdio.h>
#include<string.h>
#define maxn 3*100000+1

/**
字符串的调整与替换
https://www.nowcoder.com/practice/62caec1507ac47548670a31c5ff8a8b7?tpId=101&tqId=33172&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
https://www.nowcoder.com/practice/c53c017b757d4c02b6666b40bfa49a27?tpId=101&tqId=33183&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

char s[maxn];

void fun1()
{
    int i=0,j=0;
    int c=-1;
    while((c=getc(stdin))!=-1)
    {
        s[i]=c;
        i++;
        if(c==' ')
            j++;
    }
    int p=i+j*2-1;
    int q=i-1;
    while(p>=0)
    {
        if(s[q]==' ')
        {
            s[p--]='0';
            s[p--]='2';
            s[p--]='%';
        }
        else
        {
            s[p--]=s[q];
        }
        q--;
    }
    s[i+j*2]='\0';
    printf("%s",s);
}

void fun2(){
    scanf("%s",s);
    int i=strlen(s)-1;
    int j=i;
    while(i>=0){
        if(s[i]!='*'){
            s[j--]=s[i--];
        }
        else
            i--;
    }
    while(j>=0){
        s[j--]='*';
    }
    printf("%s",s);
}

int main()
{
    freopen("data.in","r",stdin);
    fun2();
    return 0;
}
