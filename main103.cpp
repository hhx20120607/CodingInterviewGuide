#include<stdio.h>
#include<stdlib.h>

/**
从5随机到7及其扩展
**/

int rand1To5()
{
    return rand()%5+1;
}

int rand1To7()
{
    int t;
    do
    {
        t=(rand1To5()-1)+(rand1To5()-1)*5;
    }
    while(t>6);
    return t+1;
}

int rand01p()
{
    double p=0.83;
    return rand()*1.0/RAND_MAX<p?0:1;
}

int rand01()
{
    int t;
    do
    {
        t=rand01p();
    }
    while(t==rand01p());
    return t;
}

int rand1To6()
{
    int t;
    do
    {
        t=rand01()*5+rand01()+rand01()*2;
    }
    while(t>5);
    return t+1;
}

int rand0ToM(int m)
{
    return rand()%(m+1);
}

int getK(int m,int n)
{
    int t=m+1;
    int k=0;
    while(t-1<n)
    {
        t*=(m+1);
        k++;
    }
    return k;
}

int rand0ToN(int m,int n)
{
    int s;
    if(m>n)
    {
        do
        {
            s=rand0ToM(m);
        }
        while(s>n);
    }
    else
    {
        int k=getK(m,n);
        do
        {
            s=0;
            for(int i=0; i<=k; i++)
            {
                s=s*(m+1)+rand0ToM(m);
            }
        }
        while(s>n);
    }
    return s;
}

int main()
{
    for(int i=0; i<100; i++)
        printf("%d ",rand0ToN(10,30));
    return 0;
}
