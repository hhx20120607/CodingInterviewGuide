#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
斐波那契系列问题的递归和动态规划
https://www.nowcoder.com/practice/fd66768dc08748f2be6626f07a02e466?tpId=101&tqId=33252&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

typedef struct
{
    int scale;
    long long** elements;
} matrix;


long long maxn=(long long)(1e9 + 7) ;

void initMatrix(matrix* &m,int scale,long long* v)
{
    m=(matrix*)malloc(sizeof(matrix));
    m->scale=scale;
    m->elements=(long long**)malloc(sizeof(long long*)*scale);
    for(int i=0; i<scale; i++)
        m->elements[i]=(long long*)malloc(sizeof(long long)*scale);
    if(v)
    {
        for(int i=0; i<scale; i++)
        {
            for(int j=0; j<scale; j++)
            {
                m->elements[i][j]=v[i*scale+j];
            }
        }
    }
    else
    {
        for(int i=0; i<scale; i++)
        {
            memset(m->elements[i],0,sizeof(long long)*scale);
        }
    }
}

void destoryMatrix(matrix* m)
{
    if(!m)
        return;
    for(int i=0;i<m->scale;i++){
        free(m->elements[i]);
    }
    free(m->elements);
    free(m);
}

matrix* multiply(const matrix* p,const matrix* q)
{
    if(!p||!q||p->scale!=q->scale)
        return NULL;
    matrix* t=NULL;
    initMatrix(t,p->scale,NULL);
    for(int i=0; i<p->scale; i++)
    {
        for(int j=0; j<p->scale; j++)
        {
            for(int k=0; k<p->scale; k++)
                t->elements[i][j]+=(p->elements[i][k]%maxn*q->elements[k][j]%maxn)%maxn;
        }
    }
    return t;
}

void copyMatrix(matrix* a,const matrix* b) {
    if(!a||!b||a->scale!=b->scale)
        return;
    for(int i=0;i<a->scale;i++){
        for(int j=0;j<a->scale;j++)
            a->elements[i][j]=b->elements[i][j];
    }
}

matrix* getPower(matrix* m,long long n)
{
    if(!m||n<1)
        return NULL;
    int scale=m->scale;
    matrix *a=NULL;
    matrix *b=NULL;
    initMatrix(a,scale,NULL);
    copyMatrix(a,m);
    long long* v=(long long*)malloc(sizeof(long long)*scale*scale);
    memset(v,0,sizeof(long long)*scale*scale);
    for(int i=0; i<scale; i++)
        v[i*scale+i]=1;
    initMatrix(b,scale,v);
    free(v);
    matrix* t=NULL;
    while(n)
    {
        if(n&1==1)
        {
            t=multiply(b,a);
            destoryMatrix(b);
            b=t;
        }
        t=multiply(a,a);
        destoryMatrix(a);
        a=t;
        n=n>>1;
    }
    destoryMatrix(a);
    return b;
}

int main()
{
    long long n;
    scanf("%lld",&n);
    if(n==1)
        printf("1\n");
    else if(n==2)
        printf("2\n");
    else
    {
        long long v[]={1,1,1,0};
        matrix *p=NULL,*q=NULL;
        initMatrix(p,2,v);
        initMatrix(q,2,NULL);
        q=getPower(p,n-2);
        printf("%d\n",(q->elements[0][0]*2+q->elements[1][0])%maxn);
        destoryMatrix(p);
        destoryMatrix(q);
    }
    return 0;
}
