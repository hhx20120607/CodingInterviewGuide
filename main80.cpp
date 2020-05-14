#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string.h>

int getMedianMedian(int* arr,int l,int r);
int select(int* arr,int l,int r,int k);


void partition(int* arr,int l,int r,int& a,int& b,int value)
{
    a=l;
    b=r;
    int i=l;
    while(i<=b)
    {
        if(arr[i]<value)
        {
            int temp=arr[a];
            arr[a]=arr[i];
            arr[i]=temp;
            a++;
            i++;
        }
        else if(arr[i]>value)
        {
            int temp=arr[b];
            arr[b]=arr[i];
            arr[i]=temp;
            b--;
        }
        else
        {
            i++;
        }
    }
}

void insertionSort(int* arr,int l,int r)
{
    for(int i=l+1; i<=r; i++)
    {
        int j=i-1;
        int temp=arr[i];
        while(j>=l&&arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int getMedian(int* arr,int l,int r)
{
    int c=r-l+1;
    int ttt=arr[l+c/2+c%2-1];
    return ttt;
}

int getMedianMedian(int* arr,int l,int r)
{
    int c=r-l+1;
    int* temp=(int*)malloc(sizeof(int)*c);
    memcpy(temp,arr+l,c*sizeof(int));
    int t=ceil(c/5.0);
    int* medians=(int*)malloc(sizeof(int)*t);
    int i=0,k=0;
    while(i<c)
    {
        int j=std::min(c-1,i+4);
        insertionSort(temp,i,j);
        medians[k++]=getMedian(temp,i,j);
        i=j+1;
    }
    free(temp);
    int ans=select(medians,0,t-1,t/2+t%2-1);
    free(medians);
    return ans;
}

int select(int* arr,int l,int r,int k)
{
    if(l==r)
        return arr[l];
    int median=getMedianMedian(arr,l,r);
    int a,b;
    partition(arr,l,r,a,b,median);
    if(k>=a&&k<=b)
        return arr[a];
    else if(k<a)
    {
        return select(arr,l,a-1,k);
    }
    else
    {
        return select(arr,b+1,r,k);
    }
}

int main()
{
    freopen("data.in","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int t=select(arr,0,n-1,k-1);
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<t){
            printf("%d ",arr[i]);
            j++;
        }
    }
    while(j<k){
        printf("%d ",t);
        j++;
    }
    return 0;
}
