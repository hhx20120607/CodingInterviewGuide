#include <stdio.h>
#include <stdlib.h>
#define maxn 500001

/**
调整搜索二叉树中两个错误的结点
https://www.nowcoder.com/practice/9caad175642e4651a175e6993df9d8b2?tpId=101&tqId=33237&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

void midOrderTraverse1(node* t,node* &n1,node* & n2,node* &pre)
{
    if(t->left)
        midOrderTraverse1(t->left,n1,n2,pre);
    if(pre&&t->data<pre->data)
    {
        if(!n1)
            n1=pre;
        n2=t;
    }
    pre=t;
    if(t->right)
        midOrderTraverse1(t->right,n1,n2,pre);
}

void getTwoErrors(node* t,node* &n1,node* &n2)
{
    node* pre=NULL;
    midOrderTraverse1(t,n1,n2,pre);
}

void midOrderTraverse2(node* t,node* &p1,node* &p2,node* n1,node* n2)
{
    if(t->left)
        midOrderTraverse2(t->left,p1,p2,n1,n2);
    if(t->left==n1||t->right==n1)
        p1=t;
    if(t->left==n2||t->right==n2)
        p2=t;
    if(t->right)
        midOrderTraverse2(t->right,p1,p2,n1,n2);
}

void midOrderTraverse3(node* t){
    if(t->left)
        midOrderTraverse3(t->left);
    printf("%d\n",t->data);
    if(t->right)
        midOrderTraverse3(t->right);
}

void getTwoParents(node* t,node* &p1,node* &p2,node* n1,node* n2)
{
    midOrderTraverse2(t,p1,p2,n1,n2);
}

void recover(node* &t,node* n1,node* n2,node* p1,node* p2)
{
    node *lc1=n1->left,*rc1=n1->right;
    node *lc2=n2->left,*rc2=n2->right;
    if(n1==t)
    {
        if(n1->right==n2)
        {
            n1->left=lc2;
            n1->right=rc2;
            n2->left=lc1;
            n2->right=n1;
            t=n2;
        }
        else if(p2->left==n2)
        {
            n2->left=lc1;
            n2->right=rc1;
            n1->left=lc2;
            n1->right=rc2;
            p2->left=n1;
            t=n2;
        }
        else
        {
            n2->left=lc1;
            n2->right=rc1;
            n1->left=lc2;
            n1->right=rc2;
            p2->right=n1;
            t=n2;
        }
    }
    else if(n2==t)
    {
        if(n2->left==n1)
        {
            n2->left=lc1;
            n2->right=rc1;
            n1->left=n2;
            n1->right=rc2;
            t=n1;
        }
        else if(p1->left==n1)
        {
            n2->left=lc1;
            n2->right=rc1;
            n1->left=lc2;
            n1->right=rc2;
            p1->left=n2;
            t=n1;
        }
        else
        {
            n2->left=lc1;
            n2->right=rc1;
            n1->left=lc2;
            n1->right=rc2;
            p1->right=n2;
            t=n1;
        }
    }
    else if(n1->right==n2)
    {
        if(p1->left==n1)
        {
            n1->left=lc2;
            n1->right=rc2;
            n2->left=lc1;
            n2->right=n1;
            p1->left=n2;
        }
        else
        {
            n1->left=lc2;
            n1->right=rc2;
            n2->left=lc1;
            n2->right=n1;
            p1->right=n2;
        }
    }
    else if(n2->left==n1)
    {
        if(p2->left==n2)
        {
            n2->left=lc1;
            n2->right=rc1;
            n1->left=n2;
            n1->right=rc2;
            p2->left=n1;
        }
        else
        {
            n2->left=lc1;
            n2->right=rc1;
            n1->left=n2;
            n1->right=rc2;
            p2->right=n1;
        }
    }
    else if(p1->left==n1)
    {
        if(p2->left==n2)
        {
            n1->left=lc2;
            n1->right=rc2;
            n2->left=lc1;
            n2->right=rc1;
            p1->left=n2;
            p2->left=n1;
        }
        else
        {
            n1->left=lc2;
            n1->right=rc2;
            n2->left=lc1;
            n2->right=rc1;
            p1->left=n2;
            p2->right=n1;
        }
    }
    else
    {
        if(p2->left==n2)
        {
            n1->left=lc2;
            n1->right=rc2;
            n2->left=lc1;
            n2->right=rc1;
            p1->right=n2;
            p2->left=n1;

        }
        else
        {
            n1->left=lc2;
            n1->right=rc2;
            n2->left=lc1;
            n2->right=rc1;
            p1->right=n2;
            p2->right=n1;
        }
    }
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
    node *n1=NULL,*n2=NULL,*t=&nodes[r];
    getTwoErrors(t,n1,n2);
    printf("%d %d\n",n2->data,n1->data);
    node *p1=NULL,*p2=NULL;

    getTwoParents(t,p1,p2,n1,n2);
    int data=p2->data;
    recover(t,n1,n2,p1,p2);
    midOrderTraverse3(t);
    return 0;
}
