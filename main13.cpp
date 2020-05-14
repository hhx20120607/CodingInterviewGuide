#include <stdio.h>
#include <stdlib.h>
#define maxn 2001

/**
判断1树是否包含t2树全部的拓扑结构
https://www.nowcoder.com/practice/c9fe427263844505b82c6ebb7336d04a?tpId=101&tqId=33238&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

bool match(node* t1,node* t2)
{
    if(t1&&!t2||!t1&&!t2)
        return true;
    else if(!t1&&t2)
        return false;
    else if(t1->data!=t2->data)
        return false;
    else return match(t1->left,t2->left)&&match(t1->right,t2->right);
}

bool contain(node* t1,node* t2)
{
    if(t1->left&&contain(t1->left,t2))
        return true;
    if(t1->right&&contain(t1->right,t2))
        return true;
    if(match(t1,t2))
        return true;
    return false;
}

int main()
{
    freopen("data.in","r",stdin);
    node *t1=NULL,*t2=NULL;
    int n1,r1;
    scanf("%d%d",&n1,&r1);
    for(int i=0; i<n1; i++)
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
    int n2,r2;
    scanf("%d%d",&n2,&r2);
    for(int i=0; i<n2; i++)
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
    if(contain(&nodes[r1],&nodes[r2]))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
