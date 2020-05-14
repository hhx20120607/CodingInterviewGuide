#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    char* s=(char*)malloc(sizeof(char)*11);
    scanf("%s",s);
    char** arr=(char**)malloc(sizeof(char*)*n);
    for(int i=0; i<n; i++)
    {
        arr[i]=(char*)malloc(sizeof(char)*11);
        scanf("%s",arr[i]);
        if(strcmp(arr[i],"0")==0)
            arr[i]=NULL;
    }
    int l=0,r=n-1;
    int ans=-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(arr[m]&&strcmp(arr[m],s)==0)
        {
            ans=m;
            r=m-1;
        }
        else if(arr[m])
        {
            if(strcmp(arr[m],s)<0)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        else
        {
            int k=m-1;
            while(k>=l&&!arr[k])
                k--;
            if(k<l)
            {
                l=m+1;
            }
            else if(strcmp(arr[k],s)<0)
            {
                l=m+1;
            }
            else if(strcmp(arr[k],s)==0)
            {
                ans=k;
                r=k-1;
            }
            else
            {
                r=k-1;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
