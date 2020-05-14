#include<stdio.h>
#include<stdlib.h>

/**
不重复打印排序数组中相加和为给定值的所有三元组
https://www.nowcoder.com/practice/11b7dd7cbf064900bc664bb5fd4e2fab?tpId=101&tqId=33072&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

int main()
{
    freopen("data.in","r",stdin);
    int n,s;
    scanf("%d%d",&n,&s);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    for(int i=0; i<n; i++)
    {
        if(i==0||arr[i]!=arr[i-1])
        {
            int j=i+1,k=n-1;
            while(j<k)
            {
                int sum=arr[i]+arr[j]+arr[k];
                if(sum==s)
                {
                    if(j==i||arr[j]!=arr[j-1]){
                        printf("%d %d %d\n",arr[i],arr[j],arr[k]);
                    }
                    j++;
                }
                else if(sum>s){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
    }
    return 0;
}
