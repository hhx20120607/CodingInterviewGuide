#include <stdio.h>
#include <stdlib.h>

/**
矩阵的最小路径和
https://www.nowcoder.com/practice/2fb62a4500af4f4ba5686c891eaad4a9?tpId=101&tqId=33254&tPage=2&rp=2&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

int main()
{
    freopen("data.in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int* arr=(int*)malloc(sizeof(int)*m);
    for(int i=0; i<m; i++)
    {
        scanf("%d",&arr[i]);
        if(i)
        {
            arr[i]+=arr[i-1];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int t;
            scanf("%d",&t);
            if(j)
                arr[j]=arr[j-1]>arr[j]?arr[j]:arr[j-1];
            arr[j]+=t;
        }
    }
    printf("%d\n",arr[m-1]);
    return 0;
}
