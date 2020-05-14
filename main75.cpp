#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
    freopen("data.in","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[32];
    memset(arr,0,sizeof(int)*32);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        int b=1;
        for(int j=0;j<32;j++){
            if((a&b)!=0)
                arr[j]+=1;
            b=b<<1;
        }
    }
    long long sum=0;
    for(int i=0;i<32;i++){
        sum=sum*2+arr[31-i]%k;
    }
    int ans;
    if(arr[31]%2==1)
        ans=sum-pow(2,32);
    else
        ans=sum;
    printf("%d\n",ans);
    return 0;
}
