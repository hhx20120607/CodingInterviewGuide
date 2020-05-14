#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

/**
��ˮ���㷨��������ˮ���㷨�ĳ齱ģ��
�ص㣺��ʱ�齱����ʱ����
**/

using namespace std;

typedef struct
{
    int* res; // �齱���
    int k; // ������
    int n; // ��������
} lottery;

void init(lottery* &l,int k)
{
    l=(lottery*)malloc(sizeof(lottery));
    l->res=(int*)malloc(sizeof(int)*l->k);
    memset(l->res,0,sizeof(int)*l->k);
    l->k=k;
    l->n=0;
}

int getRandom(int n)
{
    return rand()%n+1;
}

void draw(lottery* l,int id)
{
    l->n++;
    if(l->n<=l->k)
    {
        l->res[l->n-1]=id;
    }
    else
    {
        // �齱�ɹ�
        if(getRandom(l->n)<=l->k)
        {
            int idx=getRandom(l->k)-1;
            l->res[idx]=id;
        }
    }
}

void publish(lottery* const l)
{
    int c=l->n<l->k?l->n:l->k;
    for(int i=0; i<c; i++)
        printf("%d\n",l->res[i]);
}

void destory(lottery* &l)
{
    if(l)
    {
        free(l->res);
        l->res=NULL;
        free(l);
        l=NULL;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    lottery* l=NULL;
    init(l,10);
    for(int i=0; i<50; i++)
    {
        draw(l,i);
    }
    publish(l);
    destory(l);
    return 0;
}
