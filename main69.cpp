#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

typedef struct node
{
    int prefix;
    int tail;
    struct node* child[26];
} node;


void init(node* &n)
{
    n=(node*)malloc(sizeof(node));
    for(int i=0; i<26; i++)
        n->child[i]=NULL;
    n->prefix=0;
    n->tail=0;
}

void add(node* &t,char* s)
{
    node* c=t;
    int n=strlen(s);
    for(int i=0; i<n; i++)
    {
        if(!c->child[s[i]-'a'])
            init(c->child[s[i]-'a']);
        c->child[s[i]-'a']->prefix++;
        c=c->child[s[i]-'a'];
    }
    c->tail++;
}

void del(node* &t,char* s)
{
    node* c=t;
    int n=strlen(s);
    for(int i=0; i<n; i++)
    {
        c->child[s[i]-'a']->prefix--;
        c=c->child[s[i]-'a'];
    }
    c->tail--;
}

int get(node* t,char* s)
{
    node* c=t;
    int n=strlen(s);
    for(int i=0; i<n; i++)
    {
        if(!c->child[s[i]-'a'])
            return 0;
        c=c->child[s[i]-'a'];
    }
    return c->prefix;
}

bool has(node* t,char* s)
{
    node* c=t;
    int n=strlen(s);
    for(int i=0; i<n; i++)
    {
        if(!c->child[s[i]-'a'])
            return false;
        c=c->child[s[i]-'a'];
    }
    return c->tail;
}

char s[21];

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    node* t=NULL;
    init(t);
    for(int i=0; i<n; i++)
    {
        int o;
        scanf("%d %s",&o,s);
        switch(o)
        {
        case 1:
            add(t,s);
            break;
        case 2:
            del(t,s);
            break;
        case 3:
            if(has(t,s)>0)
                printf("YES\n");
            else
                printf("NO\n");
            break;
        case 4:
            printf("%d\n",get(t,s));
            break;
        default:
            break;
        }
    }
    return 0;
}
