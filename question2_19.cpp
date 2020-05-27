#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#define maxn 100001

/**
在二叉树中找到两个节点的最近公共祖先
https://www.nowcoder.com/practice/66a813f33f1e499e816ddca216aa1983?tpId=101&tqId=33246&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

typedef struct node
{
    int data;
    node* left;
    node* right;
} node;

node nodes[maxn];

map<node*,node*> father;
map<node*,int> scale;
map<node*,vector<node*> > queryMap;
map<node*,vector<int> > indexMap;
map<node*,node*> ancestor;
vector<node*> ans;

void preOrderTraverse(node* t)
{
    if(!t)
        return;
    father[t]=t;
    scale[t]=1;
    preOrderTraverse(t->left);
    preOrderTraverse(t->right);
}

void init(node* t)
{
    preOrderTraverse(t);
}

node* findFather(node* n)
{
    node* f=n;
    while(f!=father[f])
        f=father[f];
    while(father[n]!=f)
    {
        node* t=father[n];
        father[n]=f;
        n=t;
    }
    return f;
}

void join(node* a,node* b)
{
    node* fa=findFather(a);
    node* fb=findFather(b);
    int sa=scale[fa];
    int sb=scale[fb];
    if(sa>sb)
    {
        father[fb]=fa;
    }
    else if(sa<sb)
    {
        father[fa]=fb;
    }
    else
    {
        father[fa]=fb;
        scale[fb]++;
    }
}

void midOrderTraverse(node* t){
    if(!t)
        return;
    midOrderTraverse(t->left);
    if(t->left)
        join(t,t->left);
    ancestor[findFather(t)]=t;
    midOrderTraverse(t->right);
    if(t->right)
        join(t,t->right);
    ancestor[findFather(t)]=t;
    vector<node*> queryList=queryMap[t];
    vector<int> indexList=indexMap[t];
    for(int i=0;i<queryList.size();i++){
        if(ancestor.find(findFather(queryList[i]))!=ancestor.end()){
            ans[indexList[i]]=ancestor[findFather(queryList[i])];
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
    int c;
    scanf("%d",&c);
    for(int i=0;i<c;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        queryMap[&nodes[a]].push_back(&nodes[b]);
        queryMap[&nodes[b]].push_back(&nodes[a]);
        indexMap[&nodes[a]].push_back(i);
        indexMap[&nodes[b]].push_back(i);
        ans.push_back(NULL);
    }
    init(&nodes[r]);
    midOrderTraverse(&nodes[r]);
    for(int i=0;i<ans.size();i++){
        printf("%d\n",ans[i]->data);
    }
    return 0;
}
