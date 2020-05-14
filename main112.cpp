#include<stdio.h>
#include<map>

typedef struct node
{
    int key;
    int val;
    struct node* prev;
    struct node* next;
} node;

typedef struct
{
    node* head;
    node* tail;
    int k;
    std::map<int,node*>* map1;
} cache;

void init(cache* &c,int k)
{
    c=(cache*)malloc(sizeof(cache));
    c->head=NULL;
    c->tail=NULL;
    c->k=k;
    c->map1=new std::map<int,node*>();
}

static void rmv(cache* &c,node* t)
{
    if(t->prev)
    {
        t->prev->next=t->next;
    }
    else
    {
        c->head=t->next;
    }
    if(t->next)
    {
        t->next->prev=t->prev;
    }
    else
    {
        c->tail=t->prev;
    }
}

static void mov(cache* &c,node* t)
{
    if(c->head)
    {
        c->tail->next=t;
        t->prev=c->tail;
        c->tail=t;
    }
    else
    {
        c->head=t;
        c->tail=t;
    }
}

int get(cache* &c,int key)
{
    if(c->map1->find(key)!=c->map1->end())
    {
        node* t=(*(c->map1))[key];
        rmv(c,t);
        mov(c,t);
        return t->val;
    }
    return -1;
}

void set(cache* &c,int key,int val)
{
    node* t=NULL;
    if(c->map1->find(key)!=c->map1->end())
    {
        t=(*(c->map1))[key];
        rmv(c,t);
    }
    else
    {
        t=(node*)malloc(sizeof(node));
        t->key=key;
        t->prev=NULL;
        t->next=NULL;
        (*(c->map1))[key]=t;
    }
    t->val=val;
    mov(c,t);
    if(c->map1->size()>c->k)
    {
        c->map1->erase(c->map1->find(c->head->key));
        rmv(c,c->head);
    }
}

void destory(cache* &c)
{
    if(c)
    {
        delete(c->map1);
        node* t=c->head;
        while(t&&t!=c->tail)
        {
            node* n=t->next;
            free(t);
            t=n;
        }
        if(c->tail)
            free(c->tail);
        free(c);
        c=NULL;
    }
}

int main()
{
    freopen("data.in","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    cache* c=NULL;
    init(c,k);
    for(int i=0; i<n; i++)
    {
        int o,key,val;
        scanf("%d",&o);
        switch(o)
        {
        case 1:
            scanf("%d%d",&key,&val);
            set(c,key,val);
            break;
        case 2:
            scanf("%d",&key);
            printf("%d\n",get(c,key));
            break;
        default:
            break;
        }
    }
    destory(c);
    return 0;
}
