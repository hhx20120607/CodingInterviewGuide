#include <stdio.h>
#include <stdlib.h>
#include <map>

/*
通过先序和中序数组生成后序数组
https://www.nowcoder.com/practice/5ae5174f17674e458028ce12bc8bfe0b?tpId=101&tqId=33248&tPage=3&rp=3&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
*/

using namespace std;

void getPost(int* pre,int pL,int pR,int* mid,int mL,int mR,int* post,int poL,int poR,map<int,int> &map1)
{
    if(pL>pR||mL>mR)
        return;
    post[poR]=pre[pL];
    int l=map1[pre[pL]]-mL;
    int r=mR-map1[pre[pL]];
    getPost(pre,pL+1,pL+l,mid,mL,mL+l-1,post,poL,poL+l-1,map1);
    getPost(pre,pR-r+1,pR,mid,mR-r+1,mR,post,poR-r,poR-1,map1);
}

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int *pre=(int*)malloc(sizeof(int)*n),*mid=(int*)malloc(sizeof(int)*n),*post=(int*)malloc(sizeof(int)*n);
    map<int,int> map1;
    for(int i=0; i<n; i++)
        scanf("%d",pre+i);
    for(int i=0; i<n; i++)
        scanf("%d",mid+i);
    for(int i=0; i<n; i++)
        map1[mid[i]]=i;
    getPost(pre,0,n-1,mid,0,n-1,post,0,n-1,map1);
    for(int i=0; i<n; i++)
    {
        printf("%d",post[i]);
        if(i!=n-1)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}

