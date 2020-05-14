#include <stdio.h>
#include <stack>
#include <map>
#define maxn 1000001

/*
 分别用递归和非递归方式实现二叉树先序、中序和后序遍历
 https://www.nowcoder.com/practice/566f7f9d68c24691aa5abd8abefa798c?tpId=101&tqId=33229&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-rankings
*/

using namespace std;

typedef struct node
{
    int left;
    int right;
    int index;
} node;

static node nodes[maxn];

void preOrderTraverse(int r,int &first)
{
    if(!first)
        printf(" ");
    else
        first=0;
    printf("%d",nodes[r].index);
    if(nodes[r].left!=0)
        preOrderTraverse(nodes[r].left,first);
    if(nodes[r].right!=0)
        preOrderTraverse(nodes[r].right,first);
}

void midOrderTraverse(int r,int &first)
{
    if(nodes[r].left!=0)
        midOrderTraverse(nodes[r].left,first);
    if(!first)
        printf(" ");
    else
        first=0;
    printf("%d",nodes[r].index);
    if(nodes[r].right!=0)
        midOrderTraverse(nodes[r].right,first);
}

void postOrderTraverse(int r,int &first)
{
    if(nodes[r].left!=0)
        postOrderTraverse(nodes[r].left,first);
    if(nodes[r].right!=0)
        postOrderTraverse(nodes[r].right,first);
    if(!first)
        printf(" ");
    else
        first=0;
    printf("%d",nodes[r].index);
}

void preOrderTraverse2(int r)
{
    stack<node> stack1;
    if(r!=0)
        stack1.push(nodes[r]);
    int first=1;
    while(stack1.size()!=0)
    {
        if(!first)
            printf(" ");
        else
            first=0;
        node cur=stack1.top();
        stack1.pop();
        printf("%d",cur.index);
        if(cur.right!=0)
            stack1.push(nodes[cur.right]);
        if(cur.left!=0)
            stack1.push(nodes[cur.left]);
    }
}

void midOrderTraverse2(int r)
{
    stack<node> stack1;
    node cur=nodes[r];
    int first=1;
    while(cur.index!=0||stack1.size()!=0)
    {
        if(cur.index!=0)
        {
            stack1.push(cur);
            cur=nodes[cur.left];
        }
        else
        {
            node top=stack1.top();
            stack1.pop();
            if(!first)
                printf(" ");
            else
                first=0;
            printf("%d",top.index);
            cur=nodes[top.right];
        }
    }
}

void postOrderTraverse2(int r)
{
    stack<node> stack1;
    stack<node> stack2;
    if(r!=0)
        stack1.push(nodes[r]);
    while(stack1.size()!=0)
    {
        node cur=stack1.top();
        stack1.pop();
        stack2.push(cur);
        if(cur.left!=0)
            stack1.push(nodes[cur.left]);
        if(cur.right!=0)
            stack1.push(nodes[cur.right]);
    }
    int first=1;
    while(stack2.size()!=0)
    {
        node cur=stack2.top();
        stack2.pop();
        if(!first)
            printf(" ");
        else
            first=0;
        printf("%d",cur.index);
    }
}

void preOrderTraverse3(int r)
{
    stack<node> stack1;
    map<int,int> map1;
    if(r!=0)
        stack1.push(nodes[r]);
    int first=1;
    while(stack1.size()!=0)
    {
        node cur=stack1.top();
        switch(map1[cur.index])
        {
        case 0:
            if(!first)
                printf(" ");
            else
                first=0;
            map1[cur.index]=1;
            printf("%d",cur.index);
            break;
        case 1:
            if(cur.left!=0)
                stack1.push(nodes[cur.left]);
            map1[cur.index]=2;
            break;
        case 2:
            if(cur.right!=0)
                stack1.push(nodes[cur.right]);
            map1[cur.index]=3;
            break;
        case 3:
            stack1.pop();
            break;
        }
    }
}

void midOrderTraverse3(int r)
{
    stack<node> stack1;
    map<int,int> map1;
    if(r!=0)
        stack1.push(nodes[r]);
    int first=1;
    while(stack1.size()!=0)
    {
        node cur=stack1.top();
        switch(map1[cur.index])
        {
        case 0:
            if(cur.left!=0)
                stack1.push(nodes[cur.left]);
            map1[cur.index]=1;
            break;
        case 1:
            if(!first)
                printf(" ");
            else
                first=0;
            printf("%d",cur.index);
            map1[cur.index]=2;
            break;
        case 2:
            if(cur.right!=0)
                stack1.push(nodes[cur.right]);
            map1[cur.index]=3;
            break;
        case 3:
            stack1.pop();
            break;
        }
    }
}

void postOrderTraverse3(int r)
{
    stack<node> stack1;
    map<int,int> map1;
    if(r!=0)
        stack1.push(nodes[r]);
    int first=1;
    while(stack1.size()!=0)
    {
        node cur=stack1.top();
        switch(map1[cur.index])
        {
        case 0:
            if(cur.left!=0)
                stack1.push(nodes[cur.left]);
            map1[cur.index]=1;
            break;
        case 1:
            if(cur.right!=0)
                stack1.push(nodes[cur.right]);
            map1[cur.index]=2;
            break;
        case 2:
            if(!first)
                printf(" ");
            else
                first=0;
            printf("%d",cur.index);
            map1[cur.index]=3;
            break;
        case 3:
            stack1.pop();
            break;
        }
    }
}

/* 实现二叉树先序，中序和后序遍历 */
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
    return 0;
}
