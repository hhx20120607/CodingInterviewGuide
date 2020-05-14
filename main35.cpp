#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
ººÅµËþÎÊÌâ
https://www.nowcoder.com/practice/5e6750d93d23456fbe47b9ebf2cb1059?tpId=101&tqId=33098&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
*/

long long maxn=(long long)(1e9+7);

long long getPower(int a,int n)
{
    long long p=1,q=(long long)a%maxn;
    while(n)
    {
        if(n&1==1)
            p=(p%maxn)*(q%maxn);
        q=q%maxn;
        q=q*q;
        n=n>>1;
    }
    return p;
}


int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    long long ans=0;
    int left=1,mid=2,right=3,temp;
    n--;
    while(n>=0){
        int ttt=arr[n];
        if(arr[n]==left){
            temp=mid;
            mid=right;
            right=temp;
        }
        else if(arr[n]==right){
            ans+=getPower(2,n)%maxn;
            temp=left;
            left=mid;
            mid=temp;
        }
        else
            break;
        n--;
    }
    if(n==-1)
        printf("%lld\n",ans%maxn);
    else
        printf("-1\n");
    return 0;
}
