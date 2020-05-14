#include <stdio.h>
#include <stdlib.h>
#include <map>
#define maxn 1001

/**
在二叉树中找到两个节点的最近公共祖先
https://www.nowcoder.com/practice/357a9856c629405a8405d293bd6be2d1?tpId=101&tqId=33245&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];
map<node*,node*> map1;
map<node*,int> map2;

void constructMap(node* t,node* p,int level)
{
    map1[t]=p;
    map2[t]=level;
    if(t->left)
        constructMap(t->left,t,level+1);
    if(t->right)
        constructMap(t->right,t,level+1);
}

node* getLowestAncestor(node* a,node* b)
{
    if(!a||!b||map1.find(a)==map1.end()||map1.find(b)==map1.end())
        return NULL;
    int level1=map2[a];
    int level2=map2[b];
    if(level1<level2)
    {
        node* t=a;
        a=b;
        b=t;
    }
    int d=level1-level2;
    d=d>0?d:-d;
    while(d)
    {
        a=map1[a];
        d--;
    }
    while(a!=b)
    {
        a=map1[a];
        b=map1[b];
    }
    return a;
}

int main()
{
    freopen("data.in","r",stdin);
    int n,r;
    scanf("%d%d",&n,&r);
    for(int i=0; i<n; i++)
    {
        int index,left,right;
        scanf("%d%d%d",&index,&left,&right);
        nodes[index].data=index;
        if(left)
            nodes[index].left=&nodes[left];
        else
            nodes[index].left=NULL;
        if(right)
            nodes[index].right=&nodes[right];
        else
            nodes[index].right=NULL;
    }
    constructMap(&nodes[r],NULL,0);
    int c;
    scanf("%d",&c);
    for(int i=0; i<c; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        node* ans=getLowestAncestor(&nodes[a],&nodes[b]);
        if(ans)
            printf("%d\n",ans->data);
        else
            printf("0\n");
    }
    return 0;
}
