#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#define maxn 1000001

/**
 找到二叉树中的最大搜索二叉子树
 https://www.nowcoder.com/practice/380d49d7f99242709ab4b91c36bf2acc?tpId=101&tqId=33234&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

typedef struct
{
    int minData;
    int maxData;
    node* n;
    int c;
} res;

void resInit(res* r)
{
    r->minData=INT_MAX;
    r->maxData=INT_MIN;
    r->n=NULL;
    r->c=0;
}

void postOrderTraverse(node* t,res* r)
{
    res* lR=(res*)malloc(sizeof(res));
    res* rR=(res*)malloc(sizeof(res));
    resInit(lR);
    resInit(rR);
    int ttt=t->data;
    if(t->left)
        postOrderTraverse(t->left,lR);
    if(t->right)
        postOrderTraverse(t->right,rR);
    r->maxData=max(t->data,rR->maxData);
    r->minData=min(t->data,lR->minData);
    if(t->left==lR->n&&t->right==rR->n&&lR->maxData<t->data&&rR->minData>t->data)
    {
        r->c=lR->c+rR->c+1;
        r->n=t;
        return;

    }
    if(lR->c>rR->c)
    {
        r->c=lR->c;
        r->n=lR->n;
    }
    else
    {
        r->c=rR->c;
        r->n=rR->n;
    }
    free(lR);
    free(rR);
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
    res* ans=(res*)malloc(sizeof(res));
    postOrderTraverse(&nodes[r],ans);
    printf("%d\n",ans->c);
    free(ans);
    return 0;
}

