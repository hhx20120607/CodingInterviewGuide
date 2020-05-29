#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<stdlib.h>

/**
未排序数组中累加和小于或等于给定值的最长子数组长度
https://www.nowcoder.com/practice/3473e545d6924077a4f7cbc850408ade?tpId=101&tqId=33082&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

int getFirstGreaterOrEqual(int* arr,int l,int r,int val)
{
    while(l<r)
    {
        int m=(l+r)/2;
        if(arr[m]<val)
            l=m+1;
        else
            r=m;
    }
    if(arr[l]>=val)
        return l;
    else
        return -1;
}

int main()
{
    freopen("data.in","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    int* arr=(int*)malloc(sizeof(int)*n);
    int* sum=(int*)malloc(sizeof(int)*n);
    int s=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
        s+=arr[i];
        sum[i]=s;
    }
    int b=INT_MIN;
    for(int i=0;i<n;i++){
        b=max(b,sum[i]);
        sum[i]=b;
    }
    s=0;
    int ans=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
        int t=s-k;
        int len=0;
        if(t<=0){
            len=i+1;
        }
        else{
            int j=getFirstGreaterOrEqual(sum,0,n-1,t);
            if(j!=-1&&j<i)
                len=i-j;
        }
        if(len>ans)
            ans=len;
    }
    printf("%d\n",ans);
    return 0;
}
