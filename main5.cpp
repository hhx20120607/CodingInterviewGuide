#include <stdio.h>
#include <stdlib.h>
#define maxn 1000001

/**
 遍历二叉树的神级方法
 https://www.nowcoder.com/practice/5abcb95fe19d475a989dac3ba53e4635?tpId=101&tqId=33232&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

void midOrderTraverse_thread(node* t)
{
    node* cur1=t;
    node* cur2=NULL;
    while(cur1)
    {
        cur2=cur1->left;
        if(cur2)
        {
            while(cur2->right&&cur2->right!=cur1)
                cur2=cur2->right;
            if(cur2->right)
                cur2->right=NULL;
            else
            {
                cur2->right=cur1;
                cur1=cur1->left;
                continue;
            }
        }
        printf("%d ",cur1->data);
        cur1=cur1->right;
    }
}

void preOrderTraverse_thread(node* t)
{
    node* cur1=t;
    node* cur2=NULL;
    while(cur1)
    {
        int ttt=cur1->data;
        cur2=cur1->left;
        if(cur2)
        {
            while(cur2->right&&cur2->right!=cur1)
                cur2=cur2->right;
            if(cur2->right)
                cur2->right=NULL;
            else
            {
                cur2->right=cur1;
                printf("%d ",cur1->data);
                cur1=cur1->left;
                continue;
            }
        }
        else
            printf("%d ",cur1->data);
        cur1=cur1->right;
    }
}

node* reverseEdge(node* t)
{
    node* pre=NULL;
    while(t)
    {
        node* next=t->right;
        t->right=pre;
        pre=t;
        t=next;
    }
    return pre;
}

node* printEdge(node* t)
{
    node* tail=reverseEdge(t);
    node* cur=tail;
    while(cur)
    {
        printf("%d ",cur->data);
        cur=cur->right;
    }
    reverseEdge(tail);
}

void postOrderTraverse_thread(node* t)
{
    node* cur1=t;
    node* cur2=NULL;
    while(cur1)
    {
        cur2=cur1->left;
        if(cur2)
        {
            while(cur2->right&&cur2->right!=cur1)
                cur2=cur2->right;
            if(cur2->right)
            {
                cur2->right=NULL;
                printEdge(cur1->left);
            }
            else
            {
                cur2->right=cur1;
                cur1=cur1->left;
                continue;
            }
        }
        cur1=cur1->right;
    }
    printEdge(t);
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
    preOrderTraverse_thread((&nodes[r]));
    printf("\n");
    midOrderTraverse_thread(&nodes[r]);
    printf("\n");
    postOrderTraverse_thread(&nodes[r]);
    printf("\n");
    return 0;
}

