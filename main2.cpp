#include <stdio.h>
#include <map>
#include <algorithm>
#include <string.h>
#define maxn 1000001

/**
打印二叉树的边界结点
https://www.nowcoder.com/practice/33b88978734c42b68699d0c7cef9b598?tpId=101&tqId=33230&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

typedef struct node
{
    int left;
    int right;
    int index;
} node;

static node nodes[maxn];
node** left;
node** right;
node** left2;
node** right2;

int getHeight(int r)
{
    if(r==0)
        return 0;
    return max(getHeight(nodes[r].left),getHeight(nodes[r].right))+1;
}

void getEdgeNode(int r,int level)
{
    if(left[level]==NULL)
        left[level]=&nodes[r];
    right[level]=&nodes[r];
    if(nodes[r].left!=0)
        getEdgeNode(nodes[r].left,level+1);
    if(nodes[r].right!=0)
        getEdgeNode(nodes[r].right,level+1);
}

void getEdgeNode2(int height){
    for(int i=0;i<height-1;i++){
        node* curL=left[i];
        node* curR=right[i];
        if(left[i+1]==&nodes[curL->left]){
            left2[i]=left[i];
            left2[i+1]=left[i+1];
        }
        if(right[i+1]==&nodes[curR->right]){
            right2[i]=right[i];
            right2[i+1]=right[i+1];
        }
    }
}


void printLeaves(int r,int& first,int level)
{
    if(nodes[r].left==0&&nodes[r].right==0&&left[level]!=&nodes[r]&&right[level]!=&nodes[r])
    {
        if(!first)
            printf(" ");
        else
            first=1;
        printf("%d",nodes[r].index);
    }
    if(nodes[r].left!=0)
        printLeaves(nodes[r].left,first,level+1);
    if(nodes[r].right!=0)
        printLeaves(nodes[r].right,first,level+1);
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
        nodes[index].index=index;
        nodes[index].left=left;
        nodes[index].right=right;
    }
    int height=getHeight(r);
    left=(node**)malloc(sizeof(node*)*height);
    left2=(node**)malloc(sizeof(node*)*height);
    right=(node**)malloc(sizeof(node*)*height);
    right2=(node**)malloc(sizeof(node*)*height);
    memset(left,0,sizeof(node*)*height);
    memset(left2,0,sizeof(node*)*height);
    memset(right,0,sizeof(node*)*height);
    memset(right2,0,sizeof(node*)*height);
    getEdgeNode(r,0);
    getEdgeNode2(height);
    int first=1;
    for(int i=0; i<height; i++)
    {
        if(!first)
            printf(" ");
        else
            first=0;
        printf("%d",left[i]->index);
    }
    printLeaves(r,first,0);
    for(int i=height-1; i>=0; i--)
    {
        if(right[i]!=left[i])
        {
            if(!first)
                printf(" ");
            else
                first=0;
            printf("%d",right[i]->index);
        }
    }
    printf("\n");
    first=1;
    for(int i=0; i<height; i++)
    {
        if(left2[i])
        {
            if(!first)
                printf(" ");
            else
                first=0;
            printf("%d",left2[i]->index);
        }
    }
    printLeaves(r,first,0);
    for(int i=height-1; i>=0; i--)
    {
        if(right2[i]&&right2[i]!=left2[i])
        {
            if(!first)
                printf(" ");
            else
                first=0;
            printf("%d",right2[i]->index);
        }
    }
    printf("\n");

    return 0;
}
