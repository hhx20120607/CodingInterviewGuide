#include<stdio.h>
#include<malloc.h>
#include<algorithm>

using namespace std;

/**
 * 正数数组的最小不可组成和
 * @return
 */

void fun1() {
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    int sml, big = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (i == 0)
            sml = arr[i];
        else if (arr[i] < sml)
            sml = arr[i];
        big += arr[i];
    }
    bool *dp = (bool *) malloc(sizeof(bool) * (big + 1));
    for (int i = 0; i < big + 1; i++)
        dp[i] = false;
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = big; j >= arr[i]; j--) {
            if (dp[j - arr[i]])
                dp[j] = true;
        }
    }
    for (int i = sml; i <= big; i++) {
        if (!dp[i]) {
            printf("%d\n", i);
            return;
        }
    }
    printf("%d\n", big + 1);
}

bool cmp(int a,int b){
    return a<b;
}

void fun2() {
    int n;
    scanf("%d", &n);
    int *arr = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr,arr+n,cmp);
    long long k=1;
    for(int i=1;i<n;i++){
        if(arr[i]>k+1){
            break;
        }
        else
            k+=arr[i];
    }
    printf("%lld\n",k+1);
}


int main() {
    freopen("data.in", "r", stdin);
    fun2();
    return 0;
}
