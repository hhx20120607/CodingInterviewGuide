#include<stdio.h>
#include<malloc.h>
#include<time.h>

/**
 * 从N个数中等概率打印M个数
 * @return
 */

int main() {
    freopen("data.in", "r", stdin);
    srand(time(NULL));
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int i=0;
    int c=n;
    while(i<n){
        int idx=rand()%c;
        printf("%d ",arr[idx]);
        int t=arr[idx];
        arr[idx]=arr[c-1];
        arr[c-1]=t;
        c--;
        i++;
    }
    return 0;
}
