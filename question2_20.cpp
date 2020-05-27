#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define maxn 500001

/**
二叉树节点间的最大距离问题
https://www.nowcoder.com/practice/88331be6da0d40749b068586dc0a2a8b?tpId=101&tqId=33247&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

void postOrderTraverse(node* t,int &h,int & d){
    if(!t){
        h=0;
        d=0;
        return;
    }
    int lH,lD,rH,rD;
    postOrderTraverse(t->left,lH,lD);
    postOrderTraverse(t->right,rH,rD);
    h=max(lH,rH)+1;
    d=max(max(lD,rD),lH+rH+1);
}

int main(){
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
    int h,d;
    postOrderTraverse(&nodes[r],h,d);
    printf("%d\n",d);
    return 0;
}


