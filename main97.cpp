#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int** arr=(int**)malloc(sizeof(int*)*n);
    int** down=(int**)malloc(sizeof(int*)*n);
    int** right=(int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++)
    {
        arr[i]=(int*)malloc(sizeof(int)*n);
        down[i]=(int*)malloc(sizeof(int)*n);
        right[i]=(int*)malloc(sizeof(int)*n);
        for(int j=0; j<n; j++)
            scanf("%d",&arr[i][j]);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=n-1; j>=0; j--)
        {
            if(j==n-1)
                down[j][i]=arr[j][i]==1?1:0;
            else
                down[j][i]=arr[j][i]==1?down[j+1][i]+1:0;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=n-1; j>=0; j--)
        {
            if(j==n-1)
                right[i][j]=arr[i][j]==1?1:0;
            else
                right[i][j]=arr[i][j]==1?right[i][j+1]+1:0;
        }
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int a=min(down[i][j],right[i][j]);
            for(int k=1; k<=a; k++)
            {
                int p=i,q=j+k-1;
                int x=i+k-1,y=j;
                if(right[x][y]>=k&&down[p][q]>=k&&k>ans)
                    ans=k;
            }
        }
    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++){
        free(arr[i]);
        free(down[i]);
        free(right[i]);
    }
    free(arr);
    free(down);
    free(right);
    return 0;
}
