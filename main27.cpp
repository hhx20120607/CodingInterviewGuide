#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define maxn 1000001

/**
统计完全二叉树的节点数
**/

using namespace std;

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

int getNodeNumber(node* t,int l,int h){
    if(!t)
        return 0;
    node* r=t->right;
    int n=l;
    while(r){
        n++;
        r=r->left;
    }
    if(n==h){
        return pow(2,h-l)+getNodeNumber(t->right,l+1,h);
    }
    else{
        return pow(2,n-l)+getNodeNumber(t->left,l+1,h+1);
    }
}

int getHeight(node* t){
    if(!t)
        return 0;
    return max(getHeight(t->left),getHeight(t->right))+1;
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
    int h=getHeight(&nodes[r]);
    printf("%d\n",getNodeNumber(&nodes[r],1,h));
    return 0;
}
