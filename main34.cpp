#include<stdio.h>
#include<stdlib.h>
#include<vector>

/**
最长递增子数列
https://www.nowcoder.com/practice/30fb9b3cab9742ecae9acda1c75bf927?tpId=101&tqId=33093&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;


int getFirstGreater(int* arr,int k,int a)
{
    int l=0,h=k,m;
    while(l<h)
    {
        m=(l+h)/2;
        if(a>=arr[m])
            l=m+1;
        else
            h=m;
    }
    if(arr[l]>a)
        return l;
    else
        return k+1;
}

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    int* dp=(int*)malloc(sizeof(int)*n);
    int* temp=(int*)malloc(sizeof(int)*n);
    int k=0;
    temp[0]=arr[0];
    dp[0]=1;
    for(int i=1; i<n; i++)
    {
        int t=getFirstGreater(temp,k,arr[i]);
        if(t==k+1)
            k++;
        temp[t]=arr[i];
        dp[i]=t+1;
    }
    int len=0;
    int index;
    for(int i=n-1;i>=0; i--)
    {
        if(dp[i]>len)
        {
            len=dp[i];
            index=i;
        }
    }
    vector<int> ans;
    ans.push_back(arr[index]);
    len--;
    int i=index;
    int j=index-1;
    while(len&&j>=0){
        if(dp[j]==dp[i]-1&&arr[j]<arr[i]){
            ans.push_back(arr[j]);
            len--;
            i=j;
        }
        j--;
    }
    for(int i=0;i<ans.size();i++){
        printf("%d",ans[ans.size()-i-1]);
        if(i!=ans.size()-1)
            printf(" ");
        else
            printf("\n");
    }
    return 0;
}
