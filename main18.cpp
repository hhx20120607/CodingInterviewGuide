#include <stdio.h>
#include <stdlib.h>

/**
通过有序数组生成平衡搜索二叉树
**/

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

void preOrderTraverse(int* arr,int l,int r,node* &t){
    if(l>r){
        t=NULL;
        return;
    }
    int k=(l+r)/2;
    t=(node*)malloc(sizeof(node));
    t->data=arr[k];
    preOrderTraverse(arr,l,k-1,t->left);
    preOrderTraverse(arr,k+1,r,t->right);
}

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    node* t=NULL;
    preOrderTraverse(arr,0,n-1,t);
    return 0;
}
