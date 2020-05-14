#include <stdio.h>
#include <stack>
#include <stdlib.h>
#define maxn 1000001

/**
如何较为直观地打印二叉树
**/
using namespace std;

typedef struct node
{
    int left;
    int right;
    int index;
    int data;
} node;

node nodes[maxn];

char* getText(int data,char prefix,int length)
{
    char* s=(char*)malloc(sizeof(char)*(length+1));
    stack<char> stack1;
    int positive=1;
    int a=data;
    if(data<0)
    {
        positive=0;
        a=-a;
    }
    stack1.push(prefix);
    while(a)
    {
        stack1.push(a%10+'0');
        a=a/10;
    }
    if(!positive)
        stack1.push('-');
    stack1.push(prefix);
    int n=stack1.size(),p=(length-n)/2,i=0;
    while(i<p)
        s[i++]=' ';
    for(int j=0; j<n; j++)
    {
        s[i++]=stack1.top();
        stack1.pop();
    }
    while(i<length)
        s[i++]=' ';
    s[i]='\0';
    return s;
}

void printNode(int r,int level,char prefix,int length){
    if(nodes[r].right!=0)
        printNode(nodes[r].right,level+1,'+',length);
    char* t=getText(nodes[r].data,prefix,length);
    int n=(level-1)*length;
    int i=0;
    while(i<n){
        printf(" ");
        i++;
    }
    printf("%s\n",t);
    if(nodes[r].left!=0)
        printNode(nodes[r].left,level+1,'-',length);
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
        nodes[index].left=left;
        nodes[index].right=right;
        nodes[index].index=index;
        nodes[index].data=data;
    }
    printNode(r,1,' ',10);
    return 0;
}




