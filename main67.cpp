#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 5001

char s[maxn];

int main()
{
    freopen("data.in","r",stdin);
    scanf("%s",s);
    int n=strlen(s);
    bool** arr=(bool**)malloc(sizeof(bool*)*n);
    for(int i=0; i<n; i++)
        arr[i]=(bool*)malloc(sizeof(bool)*n);
    int* dp=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        arr[i][i]=true;
    for(int i=0; i<n; i++)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(j+1==i)
                arr[j][i]=s[i]==s[j]?true:false;
            else if(s[i]==s[j]&&arr[j+1][i-1]==true)
                arr[j][i]=true;
            else
                arr[j][i]=false;
        }
    }

    for(int i=n-1; i>=0; i--)
    {
        if(i==n-1)
            dp[i]=0;
        else
        {
            dp[i]=1+dp[i+1];
            for(int j=i+1; j<=n-2; j++)
            {
                if(arr[i][j]&&dp[i]>dp[j+1]+1)
                    dp[i]=dp[j+1]+1;
            }
            if(arr[i][n-1]&&dp[i]>0)
                dp[i]=0;
        }
    }
    printf("%d\n",dp[0]);
    return 0;
}
