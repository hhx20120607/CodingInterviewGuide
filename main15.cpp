#include <stdio.h>
#define maxn 500001

/**
判断一颗二叉树是否为搜索二叉树和完全二叉树
https://www.nowcoder.com/practice/4e271d590b564a61a03d04c5d9c6b6e3?tpId=101&tqId=33242&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

void midOrderTraverse(node* t,node* &pre,bool &res)
{
    if(t->left)
        midOrderTraverse(t->left,pre,res);
    if(pre&&pre->data>t->data)
        res=false;
    pre=t;
    if(t->right)
        midOrderTraverse(t->right,pre,res);
}

bool isBST(node* t)
{
    node* pre=NULL;
    bool res=true;
    midOrderTraverse(t,pre,res);
    return res;
}

void preOrderTraverse(node* t,int n,int &i,int &c)
{
    if(n>i)
        i=n;
    c++;
    if(t->left)
        preOrderTraverse(t->left,2*n+1,i,c);
    if(t->right)
        preOrderTraverse(t->right,2*n+2,i,c);
}

bool isCBT(node* t)
{
    int i=-1,c=0;
    preOrderTraverse(t,0,i,c);
    return i==c-1;
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
    if(isBST(&nodes[r]))
        printf("true\n");
    else
        printf("false\n");
    if(isCBT(&nodes[r]))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}

