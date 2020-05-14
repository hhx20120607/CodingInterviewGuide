#include<stdio.h>
#include<map>

using namespace std;

map<int,int> map1;

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int ans=0;
    int cur;
    for(int i=0; i<n; i++)
    {
        if(i==0)
        {
            cur=1;
        }
        else
        {
            if(map1.find(arr[i])==map1.end()||map1[arr[i]]<i-cur)
            {
                cur++;
            }
            else
            {
                cur=i-map1[arr[i]];
            }
        }
        if(cur>ans)
            ans=cur;
        map1[arr[i]]=i;
    }
    printf("%d\n",ans);
    return 0;
}
