#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    freopen("data.in","r",stdin);
    int m,n;
    scanf("%d%d",&m,&n);
    int** arr=(int**)malloc(sizeof(int*)*m);
    for(int i=0; i<m; i++)
        arr[i]=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int ans=INT_MIN;
    int* temp=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<m; i++)
    {
        memset(temp,0,sizeof(int)*n);
        for(int j=i; j<m; j++)
        {
            for(int k=0;k<n;k++)
                temp[k]+=arr[j][k];
            int cur;
            for(int k=0;k<n;k++){
                if(k==0||cur<0)
                    cur=temp[k];
                else
                    cur+=temp[k];
                if(cur>ans)
                    ans=cur;
            }
        }
    }
    free(temp);
    printf("%d\n",ans);
    return 0;
}
