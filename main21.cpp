#include <stdio.h>
#include <stdlib.h>
#include <map>
#define maxn 500001

/*
先序、中序和后序数组两两结合重构二叉树
*/

using namespace std;

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

void constructByPreIn(node* &t,int* pre,int pL,int pR,int* in,int iL,int iR,map<int,int> &map1)
{
    if(pL>pR||iL>iR)
    {
        t=NULL;
        return;
    }
    t=(node*)malloc(sizeof(node));
    t->data=pre[pL];
    int l=map1[pre[pL]]-iL;
    int r=iR-map1[pre[pL]];
    constructByPreIn(t->left,pre,pL+1,pL+l,in,iL,iL+l-1,map1);
    constructByPreIn(t->right,pre,pR-r+1,pR,in,iR-r+1,iR,map1);
}

void constructByInPost(node* &t,int* in,int iL,int iR,int* post,int pL,int pR,map<int,int> &map2)
{
    if(iL>iR||pL>pR)
    {
        t=NULL;
        return;
    }
    t=(node*)malloc(sizeof(node));
    t->data=post[pR];
    int l=map2[post[pR]]-iL;
    int r=iR-map2[post[pR]];
    constructByInPost(t->left,in,iL,iL+l-1,post,pL,pL+l-1,map2);
    constructByInPost(t->right,in,iR-r+1,iR,post,pR-r,pR-1,map2);
}

void constructByPrePost(node* &t,int* pre,int prL,int prR,int* post,int poL,int poR,map<int,int> &map3)
{
    if(prL>prR||poL>poR)
    {
        t=NULL;
        return;
    }
    t=(node*)malloc(sizeof(node));
    t->data=pre[prL];
    if(prL+1>prR)
    {
        t->left=NULL;
        t->right=NULL;
        return;
    }
    else
    {
        int l=map3[pre[prL+1]]-poL+1;
        int r=poR-1-map3[pre[prL+1]];
        constructByPrePost(t->left,pre,prL+1,prL+l,post,poL,poL+l-1,map3);
        constructByPrePost(t->right,pre,prR-r+1,prR,post,poR-r,poR-1,map3);
    }
}

void midOrderTraverse(node* t)
{
    if(t->left)
        midOrderTraverse(t->left);
    printf("%d\n",t->data);
    if(t->right)
        midOrderTraverse(t->right);
}


int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int *pre=(int*)malloc(sizeof(int)*n),*in=(int*)malloc(sizeof(int)*n),*post=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",pre+i);
    for(int i=0; i<n; i++)
        scanf("%d",in+i);
    for(int i=0; i<n; i++)
        scanf("%d",post+i);
    map<int,int> map1,map2,map3;
    for(int i=0; i<n; i++)
    {
        map1[in[i]]=i;
        map2[in[i]]=i;
        map3[post[i]]=i;
    }
    node* t=NULL;
    constructByPrePost(t,pre,0,n-1,post,0,n-1,map3);
    midOrderTraverse(t);
    return 0;
}
