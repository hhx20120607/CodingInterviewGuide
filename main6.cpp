#include <stdio.h>
#include <stdlib.h>
#include <map>

/**
未排序数组中累加和为给定值的最长数组系列问题
https://www.nowcoder.com/practice/36fb0fd3c656480c92b569258a1223d5?tpId=101&tqId=33077&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
https://www.nowcoder.com/practice/545544c060804eceaed0bb84fcd992fb?tpId=101&tqId=33078&tPage=1&rp=1&ru=%2Fta%2Fprogrammer-code-interview-guide&qru=%2Fta%2Fprogrammer-code-interview-guide%2Fquestion-ranking
https://www.nowcoder.com/practice/ab190c44af0141d58037c3f95109d722?tpId=101&tqId=33079&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/
using namespace std;

int maxLength1(int* arr,int n,int k){
    int len=0;
    map<int,int> map1;
    map1[0]=-1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(map1.find(sum-k)!=map1.end()){
            int newLen=i-map1[sum-k];
            if(newLen>len)
                len=newLen;
        }
        if(map1.find(sum)==map1.end())
            map1[sum]=i;
    }
    return len;
}

int maxLength2(int* arr,int n){
    int len=0,diff=0;
    map<int,int> map1;
    map1[0]=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>0)
            diff++;
        else if(arr[i]<0)
            diff--;
        if(map1.find(diff)!=map1.end()){
            int newLen=i-map1[diff];
            if(newLen>len)
                len=newLen;
        }
        if(map1.find(diff)==map1.end())
            map1[diff]=i;
    }
    return len;
}

int maxLength3(int* arr,int n){
    int len=0,diff=0;
    map<int,int> map1;
    map1[0]=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==1)
            diff++;
        else if(arr[i]==0)
            diff--;
        if(map1.find(diff)!=map1.end()){
            int newLen=i-map1[diff];
            if(newLen>len)
                len=newLen;
        }
        if(map1.find(diff)==map1.end())
            map1[diff]=i;
    }
    return len;
}

int main(){
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int len=maxLength3(arr,n);
    printf("%d\n",len);
    free(arr);
    return 0;
}
