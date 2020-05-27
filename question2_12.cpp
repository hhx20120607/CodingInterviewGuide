#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#define maxn 500001

/**
判断t1树中是否有与t2树拓扑结构完全相同的子树
https://www.nowcoder.com/practice/5a41ce17e8194e1688aa83a73137f7ee?tpId=101&tqId=33239&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes1[maxn],nodes2[maxn];

void serialize(node* t,ostringstream &oss)
{
    if(!t)
        oss<<'#'<<'!';
    else
    {
        oss<<t->data<<'!';
        serialize(t->left,oss);
        serialize(t->right,oss);
    }
}

bool contain(node* t1,node* t2)
{
    ostringstream oss1,oss2;
    serialize(t1,oss1);
    serialize(t2,oss2);
    string s1=oss1.str(),s2=oss2.str();
    int i=0,j=0;
    while(i<s1.size()&&j<s2.size())
    {
        if(s1[i]==s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    return j==s2.size();
}

int main()
{
    freopen("data.in","r",stdin);
    int n1,r1;
    scanf("%d%d",&n1,&r1);
    for(int i=0; i<n1; i++)
    {
        int index,left,right;
        scanf("%d%d%d",&index,&left,&right);
        nodes1[index].data=index;
        if(left)
            nodes1[index].left=&nodes1[left];
        else
            nodes1[index].left=NULL;
        if(right)
            nodes1[index].right=&nodes1[right];
        else
            nodes1[index].right=NULL;
    }
    int n2,r2;
    scanf("%d%d",&n2,&r2);
    for(int i=0; i<n2; i++)
    {
        int index,left,right;
        scanf("%d%d%d",&index,&left,&right);
        nodes2[index].data=index;
        if(left)
            nodes2[index].left=&nodes2[left];
        else
            nodes2[index].left=NULL;
        if(right)
            nodes2[index].right=&nodes2[right];
        else
            nodes2[index].right=NULL;
    }
    if(contain(&nodes1[r1],&nodes2[r2]))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
