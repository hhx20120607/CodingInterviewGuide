#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define maxn 500001

/**
 二叉树的按层打印与ZigZag打印
 https://www.nowcoder.com/practice/6a1815a85bfc411d9295bc017e6b6dbe?tpId=101&tqId=33236&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

void construct(node* &t)
{
    int data;
    scanf("%d",&data);
    if(data)
    {
        t=(node*)malloc(sizeof(node));
        t->data=data;
        construct(t->left);
        construct(t->right);
    }
    else
        t=NULL;
}

void traverseByLevel(node* t)
{
    queue<node*> queue1;
    queue1.push(t);
    int c=queue1.size();
    int level=1;
    if(c)
        printf("Level %d :",level);
    while(!queue1.empty())
    {
        node* cur=queue1.front();
        printf(" %d",cur->data);
        if(cur->left)
            queue1.push(cur->left);
        if(cur->right)
            queue1.push(cur->right);
        queue1.pop();
        c--;
        if(!c)
        {
            printf("\n");
            c=queue1.size();
            level++;
            if(c)
                printf("Level %d :",level);
        }
    }
}

void traverseByZigZag(node* t)
{
    deque<node*> deque1;
    deque1.push_back(t);
    int c=deque1.size();
    int level=1;
    int leftToRight=1;
    if(c)
    {
        printf("Level %d",level);
        if(leftToRight)
            printf(" from left to right:");
        else
            printf(" from right to left:");
    }
    while(!deque1.empty())
    {
        if(leftToRight)
        {
            node* cur=deque1.front();
            printf(" %d",cur->data);
            if(cur->left)
                deque1.push_back(cur->left);
            if(cur->right)
                deque1.push_back(cur->right);
            deque1.pop_front();
            c--;
        }
        else
        {
            node* cur=deque1.back();
            printf(" %d",cur->data);
            if(cur->right)
                deque1.push_front(cur->right);
            if(cur->left)
                deque1.push_front(cur->left);
            deque1.pop_back();
            c--;
        }
        if(!c)
        {
            printf("\n");
            c=deque1.size();
            level++;
            leftToRight=1-leftToRight;
            if(c)
            {
                printf("Level %d",level);
                if(leftToRight)
                    printf(" from left to right:");
                else
                    printf(" from right to left:");
            }
        }
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
    traverseByLevel(&nodes[r]);
    traverseByZigZag(&nodes[r]);
    return 0;
}
