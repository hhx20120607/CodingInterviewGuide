#include <stdio.h>
#include <limits.h>
#include <algorithm>
#define maxn 500001

/**
ÅÐ¶Ï¶þ²æÊ÷ÊÇ·ñÎªÆ½ºâ¶þ²æÊ÷
https://www.nowcoder.com/practice/0d7b90d3cf454062942ff9376e1c8b7e?tpId=101&tqId=33240&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;


typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

bool postOrderTraverse(node* t,int &height)
{
    int heightL=0,heightR=0;
    if(t->left&&!postOrderTraverse(t->left,heightL))
        return false;
    if(t->right&&!postOrderTraverse(t->right,heightR))
        return false;
    height=max(heightL,heightR)+1;
    return abs(heightL-heightR)<2;
}

bool isAVL(node* t)
{
    int height;
    return postOrderTraverse(t,height);
}

int main()
{
    freopen("data.in","r",stdin);
    int n,r;
    scanf("%d%d",&n,&r);
    for(int i=0;i<n;i++){
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
    if(isAVL(&nodes[r]))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
