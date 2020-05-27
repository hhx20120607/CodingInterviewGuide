#include <stdio.h>
#include <stdlib.h>
#include <map>
#define maxn 200001

/**
在二叉树中找到累加和为指定值的最长路径长度
https://www.nowcoder.com/practice/2d35bc3364e3470381bc4eebd9178747?tpId=101&tqId=33233&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

void preOrderTraverse(node* t,int level,map<int,int> &map1,int sum,int& len,int k)
{
    sum+=t->data;
    if(map1.find(sum-k)!=map1.end())
    {
        int newLen=level-map1[sum-k];
        int tt=t->data;
        if(newLen>len)
            len=newLen;
    }
    if(map1.find(sum)==map1.end())
        map1[sum]=level;
    if(t->left)
        preOrderTraverse(t->left,level+1,map1,sum,len,k);
    if(t->right)
        preOrderTraverse(t->right,level+1,map1,sum,len,k);
    if(map1.find(sum)!=map1.end()&&map1[sum]==level)
        map1.erase(sum);
}

int getMaxLength(node* t,int k)
{
    map<int,int> map1;
    map1[0]=0;
    int len=0;
    preOrderTraverse(t,1,map1,0,len,k);
    return len;
}

int main()
{
    freopen("data.in","r",stdin);
    int n,r;
    scanf("%d%d",&n,&r);
    for(int i=0; i<n; i++)
    {
        int index,left,right,data;
        scanf("%d%d%d%d",&index,&left,&right,&data);
        nodes[index].data=data;
        if(left)
            nodes[index].left=&nodes[left];
        if(right)
            nodes[index].right=&nodes[right];
    }
    int k;
    scanf("%d",&k);
    printf("%d\n",getMaxLength(&nodes[r],k));
    return 0;
}

