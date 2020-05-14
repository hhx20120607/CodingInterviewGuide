#include<stdio.h>


int fun(int fin,int cur,int left,int right)
{
    if(fin==cur)
        return 1;
    int pos=fin&(~(cur|left|right));
    int res=0;
    while(pos)
    {
        int mostRight=(~pos+1)&pos;
        pos-=mostRight;
        res+=fun(fin,cur|mostRight,(left|mostRight)<<1,(right|mostRight)>>1);
    }
    return res;
}


int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",fun((1<<n)-1,0,0,0));
    return 0;
}


