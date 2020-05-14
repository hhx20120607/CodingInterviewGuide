#include <stdio.h>
#include <stdlib.h>
#define maxn 500001

/**
在二叉树中找到两个节点的最近公共祖先
https://www.nowcoder.com/practice/c75deef6d4bf40249c785f240dad4247?tpId=101&tqId=33244&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

void getNode(node* t,node* a,node* b,int& p,int& q)
{
    if(t->left)
        getNode(t->left,a,b,p,q);
    if(t->right)
        getNode(t->right,a,b,p,q);
    if(t==a)
        p=1;
    if(t==b)
        q=1;
}

node* getLowestAncestorOrNode(node* t,node* a,node* b)
{
    if(!t)
        return NULL;
    node* l=getLowestAncestorOrNode(t->left,a,b);
    node* r=getLowestAncestorOrNode(t->right,a,b);
    if(t==a||t==b)
        return t;
    if(l&&r)
        return t;
    else if(l)
        return l;
    else if(r)
        return r;
    else
        return NULL;
}

node* getLowestAncestor(node* t,node* a,node* b)
{
    int p=0,q=0;
    getNode(t,a,b,p,q);
    if(p&&q)
    {
        node* ans=getLowestAncestorOrNode(t,a,b);
        return ans;
    }
    return NULL;
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
    int a,b;
    scanf("%d%d",&a,&b);
    node* ans=getLowestAncestor(&nodes[r],&nodes[a],&nodes[b]);
    if(ans)
        printf("%d\n",ans->data);
    else
        printf("0\n");
    return 0;
}


