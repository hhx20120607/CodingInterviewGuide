#include<stdio.h>
#include<map>

/**
数组中的最长连续序列
https://www.nowcoder.com/practice/c6b19ebae63143baa7fbb5b6d8dc24ec?tpId=101&tqId=33161&tPage=2&rp=2&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

std::map<int,int> map1;

void merge(int a,int b)
{
    int left=a-map1[a]+1;
    int right=b+map1[b]-1;
    int length=right-left+1;
    map1[left]=length;
    map1[right]=length;
}

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    for(int i=0; i<n; i++)
    {
        if(map1.find(arr[i])==map1.end())
        {
            map1[arr[i]]=1;
            if(map1.find(arr[i]-1)!=map1.end())
            {
                merge(arr[i]-1,arr[i]);
            }
            if(map1.find(arr[i]+1)!=map1.end())
            {
                merge(arr[i],arr[i]+1);
            }
        }
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(map1[arr[i]]>ans)
            ans=map1[arr[i]];
    }
    printf("%d\n",ans);
    return 0;
}
