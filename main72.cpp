#include<stdio.h>

int add(int a,int b)
{
    while(b!=0)
    {
        int c=a^b;
        int d=(a&b)<<1;
        a=c;
        b=d;
    }
    return a;
}

int getNeg(int a)
{
    return add(~a,1);
}

int sub(int a,int b)
{
    return add(a,getNeg(b));
}

int mul(int a,int b)
{
    return a*b;
}

int div(int a,int b)
{
    return a/b;
}

int main()
{
    freopen("data.in","r",stdin);
    int a,b;
    char o;
    scanf("%d",&a);
    fgetc(stdin);
    scanf("%c",&o);
    fgetc(stdin);
    scanf("%d",&b);
    int c;
    switch(o)
    {
    case '+':
        c=add(a,b);
        break;
    case '-':
        c=sub(a,b);
        break;
    case '*':
        c=mul(a,b);
        break;
    case '\\':
        c=div(a,b);
        break;
    default:
        break;
    }
    printf("%d\n",c);
    return 0;
}
