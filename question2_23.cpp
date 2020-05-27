#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
统计和生成所有不同的二叉树
https://www.nowcoder.com/practice/3975b2a794ee419aa927b24f6495c7d6?tpId=101&tqId=33249&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

int main()
{
    int n,maxn=1e9+7;
    scanf("%d",&n);
    if(n<1)
    {
        printf("1\n");
        return 0;
    }
    long long* num=(long long*)malloc(sizeof(long long)*(n+1));
    memset(num,0,sizeof(long long)*(n+1));
    num[0]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=i-1; j++)
        {
            num[i]+=(num[j]%maxn)*(num[i-1-j]%maxn)%maxn;
        }
    }
    printf("%d\n",num[n]%maxn);
    return 0;
}
