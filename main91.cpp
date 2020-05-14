#include<stdio.h>
#include<limits.h>

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int ans=INT_MIN;
    int cur;
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d",&a);
        if(i==0 || cur<=0)
            cur=a;
        else
            cur+=a;
        if(cur>ans)
            ans=cur;
    }
    printf("%d\n",ans);
    return 0;
}
