#include<stdio.h>
#include<iostream>
#include<map>
#include<string>

/**
判断数组中所有的数字是否只出现一次
https://www.nowcoder.com/practice/33376cab7c714d46b0853a985420b977?tpId=101&tqId=33171&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

void fun1(int* arr,int length)
{
    map<int,int> map1;
    for(int i=0; i<length; i++)
        map1[arr[i]]+=1;
    for(int i=0; i<length; i++)
    {
        if(map1[arr[i]]!=1)
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

void sink(int* arr,int last,int i)
{
    while(i<=last)
    {
        int maxValue=arr[i];
        if(2*i+1<=last&&arr[2*i+1]>maxValue)
            maxValue=arr[2*i+1];
        if(2*i+2<=last&&arr[2*i+2]>maxValue)
            maxValue=arr[2*i+2];
        if(maxValue==arr[i])
            break;
        if(2*i+1<=last&&maxValue==arr[2*i+1])
        {
            int t=arr[2*i+1];
            arr[2*i+1]=arr[i];
            arr[i]=t;
            i=2*i+1;
        }
        else if(2*i+2<=last&&maxValue==arr[2*i+2])
        {
            int t=arr[2*i+2];
            arr[2*i+2]=arr[i];
            arr[i]=t;
            i=2*i+2;
        }
    }
}

void buildHeap(int* arr,int last)
{
    for(int i=(last-1)/2; i>=0; i--)
    {
        sink(arr,last,i);
    }
}

void fun2(int* arr,int length)
{
    buildHeap(arr,length-1);
    int j=length-1;
    while(j>=0)
    {
        int t=arr[j];
        arr[j]=arr[0];
        arr[0]=t;
        sink(arr,j,0);
        j--;
    }
    for(int i=1; i<length; i++)
    {
        if(arr[i]==arr[i-1])
        {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main()
{
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d",&arr[i]);
    fun2(arr,n);
    return 0;
}
