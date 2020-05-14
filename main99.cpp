#include<stdio.h>
#include<stdlib.h>


/**
数组的artition调整
**/
void fun1()
{
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    int i=0,j=1;
    while(j<n)
    {
        if(arr[i]!=arr[j])
        {
            int t=arr[i+1];
            arr[i+1]=arr[j];
            arr[j]=t;
            i++;
        }
        j++;
    }
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
}

void fun2()
{
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    int left=-1,right=n,index=0;
    while(index<right)
    {
        if(arr[index]==1)
            index++;
        else if(arr[index]==0)
        {
            int t=arr[index];
            arr[index]=arr[left+1];
            arr[left+1]=t;
            left++;
            index++;
        }
        else
        {
            int t=arr[index];
            arr[index]=arr[right-1];
            arr[right-1]=t;
            right--;
        }
    }
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);

}

int main()
{
    freopen("data.in","r",stdin);
    fun2();
    return 0;

}
