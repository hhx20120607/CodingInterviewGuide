#include <stdio.h>
#include <string>
#include <queue>
#define maxn 1000001

/**
 二叉树的序列化和反序列化
 https://www.nowcoder.com/practice/d6425eab86fc402085f9fafc0db97cc2?tpId=101&tqId=33231&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/
using namespace std;

typedef struct node
{
    int left;
    int right;
    int index;
} node;

node nodes[maxn];

void preOrderTraverse(int r,string& s)
{
    if(!r)
    {
        s.append("#!");
        return;
    }
    else
    {
        s+=to_string(nodes[r].index);
        s.push_back('!');
        preOrderTraverse(nodes[r].left,s);
        preOrderTraverse(nodes[r].right,s);
    }
}

void levelTraverse(int r,string& s)
{
    queue<node> queue1;
    if(r)
    {
        queue1.push(nodes[r]);
        s+=to_string(nodes[r].index);
        s.push_back('!');
    }
    else
        s.append("#!");
    while(!queue1.empty())
    {
        node cur=queue1.front();
        if(cur.left)
        {
            node leftN=nodes[cur.left];
            queue1.push(leftN);
            s+=to_string(leftN.index);
            s.push_back('!');
        }
        else
            s.append("#!");
        if(cur.right)
        {
            node rightN=nodes[cur.right];
            queue1.push(rightN);
            s+=to_string(rightN.index);
            s.push_back('!');
        }
        else
            s.append("#!");
        queue1.pop();
    }
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
        nodes[index].left=left;
        nodes[index].right=right;
        nodes[index].index=index;
    }
    string s1,s2;
    preOrderTraverse(r,s1);
    printf("%s\n",s1.c_str());
    levelTraverse(r,s2);
    printf("%s\n",s2.c_str());
    return 0;
}
