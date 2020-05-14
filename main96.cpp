#include<stdio.h>
#include<map>
#include<time.h>

/**
设计RandomPool结构
**/

using namespace std;

typedef struct
{
    map<int,int>* map1;
    map<int,int>* map2;
    int n;
} random_pool;

void init(random_pool* &r)
{
    r=(random_pool*)malloc(sizeof(random_pool));
    r->map1=new map<int,int>();
    r->map2=new map<int,int>();
    r->n=0;
}

void add(random_pool* &r,int k)
{
    (*(r->map1))[k]=r->n;
    (*(r->map2))[r->n]=k;
    r->n++;
}

void del(random_pool* &r,int k)
{
    if(r->n>0)
    {
        int idx1=(*(r->map1))[k];
        int idx2=r->n-1;
        int k2=(*(r->map2))[idx2];
        (*(r->map1))[k2]=idx1;
        (*(r->map1))[k]=idx2;
        (*(r->map2))[idx1]=k2;
        (*(r->map2))[idx2]=k;
        r->map1->erase(r->map1->find(k));
        r->map2->erase(r->map2->find(idx2));
        r->n--;
    }
}

int rad(random_pool* r)
{
    return (*(r->map2))[rand()%r->n];
}


int main()
{
    srand((unsigned)time(NULL));
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    random_pool* r;
    init(r);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        add(r,a);
    }
    del(r,1);
    del(r,5);
    for(int i=0;i<100;i++){
        printf("%d ",rad(r));
    }
    return 0;
}
