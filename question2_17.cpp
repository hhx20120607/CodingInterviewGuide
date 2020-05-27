#include <stdio.h>
#define maxn 500001

/**
在二叉树中找到一个节点的后继节点
https://www.nowcoder.com/practice/c37ec6a9e4084b9c943be2d3a369e177?tpId=101&tqId=33243&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

typedef struct node
{
    int data;
    node* left;
    node* right;
    node* parent;
} node;

node nodes[maxn];

node* getNextNode(node* t)
{
    if(t->right)
    {
        node* r=t->right;
        while(r->left)
            r=r->left;
        return r;
    }
    node* p=t->parent;
    if(p)
    {
        if(p->left==t)
            return p;
        while(p&&p->right==t)
        {
            t=p;
            p=t->parent;
        }
        return p;
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
        {
            nodes[index].left=&nodes[left];
            nodes[left].parent=&nodes[index];
        }
        if(right)
        {
            nodes[index].right=&nodes[right];
            nodes[right].parent=&nodes[index];
        }
    }
    int t;
    scanf("%d",&t);
    node* a=getNextNode(&nodes[t]);
    printf("%d\n",a?a->data:0);
    return 0;
}
