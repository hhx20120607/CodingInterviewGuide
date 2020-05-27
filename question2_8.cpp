#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <queue>
#define maxn 200001

/**
找到二叉树中符合搜索条件的最大拓扑结构
https://www.nowcoder.com/practice/e13bceaca5b14860b83cbcc4912c5d4a?tpId=101&tqId=33235&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

typedef struct
{
    int left;
    int right;
} res;

void postOrderTraverse(node* t,map<node*,res> &map1,int* ans)
{
    if(t->left)
        postOrderTraverse(t->left,map1,ans);
    if(t->right)
        postOrderTraverse(t->right,map1,ans);
    // 调整左子树
    queue<node*> queue1;
    node* lN=t->left;
    while(lN&&map1.find(lN)!=map1.end()&&lN->data<t->data)
    {
        queue1.push(lN);
        lN=lN->right;
    }
    if(lN&&map1.find(lN)!=map1.end())
    {
        int diff=map1[lN].left+map1[lN].right+1;
        while(!queue1.empty())
        {
            map1[queue1.front()].right-=diff;
            queue1.pop();
        }
        map1.erase(lN);
    }
    if(t->left&&map1.find(t->left)!=map1.end())
        map1[t].left=map1[t->left].left+map1[t->left].right+1;
    // 调整右子树
    queue<node*> queue2;
    node* rN=t->right;
    while(rN&&map1.find(rN)!=map1.end()&&rN->data>t->data)
    {
        queue2.push(rN);
        rN=rN->left;
    }
    if(rN&&map1.find(rN)!=map1.end())
    {
        int diff=map1[rN].left+map1[rN].right+1;
        while(!queue2.empty())
        {
            map1[queue2.front()].left-=diff;
            queue2.pop();
        }
        map1.erase(rN);
    }
    if(t->right&&map1.find(t->right)!=map1.end())
        map1[t].right=map1[t->right].left+map1[t->right].right+1;
    if(map1[t].left+map1[t].right+1>*ans)
        *ans=map1[t].left+map1[t].right+1;
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
        if(right)
            nodes[index].right=&nodes[right];
    }
    map<node*,res> map1;
    int ans=0;
    postOrderTraverse(&nodes[r],map1,&ans);
    printf("%d\n",ans);
    return 0;
}


