#include<stdio.h>
#include<stdlib.h>

/**
不重复打印排序数组中相加和为给定值的所有二元组
https://www.nowcoder.com/practice/1ff1a607c81748baa1823ffa687d74c4?tpId=101&tqId=33071&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/
int main()
{
    freopen("data.in","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    int i=0,j=n-1;
    while(i<j)
    {
        int sum=arr[i]+arr[j];
        if(sum==k)
        {
            if(i==0||arr[i]!=arr[i-1])
                printf("%d %d\n",arr[i],arr[j]);
            i++;
        }
        else if(sum>k)
            j--;
        else
            i++;
    }
    return 0;
}
