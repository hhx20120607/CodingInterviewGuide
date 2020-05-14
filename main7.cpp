#include <stdio.h>
#include <stdlib.h>

/**
未排序正数数组中累加和为给定值的最长子数组长度
https://www.nowcoder.com/practice/a4e34287fa1b41f9bd41f957efbd5dff?tpId=101&tqId=33076&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

int maxLength(int* arr,int n,int k)
{
    int left=0,right=0;
    int sum=arr[0];
    int len=0;
    while(left<n&&right<n)
    {
        if(sum==k)
        {
            if(right-left+1>len)
                len=right-left+1;
            sum-=arr[left];
            left++;
        }
        else if(sum<k)
        {
            right++;
            sum+=arr[right];
        }
        else
        {
            sum-=arr[left];
            left++;
        }
    }
    return len;
}

int main()
{
    freopen("data.in","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    int len=maxLength(arr,n,k);
    printf("%d\n",len);
    free(arr);
    return 0;
}

