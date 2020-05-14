#include<stdio.h>

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int big,a,b;
    for(int i=0; i<n; i++)
    {
        int t;
        scanf("%d",&t);
        if(i==0)
        {
            big=t;
            a=t;
        }
        else
        {
            if(t>big)
                big=t;
        }
        if(i==n-1)
            b=t;
    }
    int ans=big-a;
    if(big-b>ans)
        ans=big-b;
    printf("%d\n",ans);
    return 0;
}
