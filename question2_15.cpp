#include <stdio.h>
#include <stdlib.h>

/**
根据后序数组重建搜索二叉树
https://www.nowcoder.com/practice/f83d11c38a974cbc8973a10086be60f3?tpId=101&tqId=33241&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

bool preOrderTraverse1(int* arr,int l,int r){
    if(l>r)
        return true;
    int data=arr[r];
    int p=l,q=r-1;
    while(p<r&&arr[p]<data)
        p++;
    while(q>=l&&arr[q]>data)
        q--;
    p--;
    q++;
    if(p+1!=q)
        return false;
    return preOrderTraverse1(arr,l,p)&&preOrderTraverse1(arr,q,r-1);
}

bool preOrderTraverse2(int* arr,int l,int r,node* &t){
    if(l>r){
        t=NULL;
        return true;
    }
    int data=arr[r];
    int p=l,q=r-1;
    while(p<r&&arr[p]<data)
        p++;
    while(q>=l&&arr[q]>data)
        q--;
    p--;
    q++;
    if(p+1!=q)
        return false;
    else{
        t=(node*)malloc(sizeof(node));
        t->data=arr[r];
        return preOrderTraverse2(arr,l,p,t->left)&&preOrderTraverse2(arr,q,r-1,t->right);
    }
}

int main(){
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    node* t=NULL;
    if(preOrderTraverse2(arr,0,n-1,t))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
