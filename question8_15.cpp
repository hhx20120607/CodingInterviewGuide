#include<stdio.h>
#include<stdlib.h>

/**
奇数下标都是奇数或者偶数下标都是偶数
https://www.nowcoder.com/practice/335823db14b945ab95241a74cfcf1ae7?tpId=101&tqId=33092&tPage=2&rp=2&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

int main(){
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int even=0,odd=1;
    while(true){
        if(arr[n-1]%2==1&&odd<n){
            int t=arr[odd];
            arr[odd]=arr[n-1];
            arr[n-1]=t;
            odd+=2;
        }
        else if(arr[n-1]%2==0&&even<n){
            int t=arr[even];
            arr[even]=arr[n-1];
            arr[n-1]=t;
            even+=2;
        }
        else
            break;
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        if(i!=n-1)
            printf(" ");
    }
    printf("\n");
}
