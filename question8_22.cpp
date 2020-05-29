#include<stdio.h>
#include<stdlib.h>

/**
不包含本位置值得累乘数组
**/

int main() {
    freopen("data.in", "r", stdin);
    long long n, k;
    scanf("%lld%lld", &n, &k);
    long long *arr = (long long *) malloc(sizeof(long long) * n);
    long long *ans = (long long *) malloc(sizeof(long long) * n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    long long temp;
    for (int i = 0; i < n; i++) {
        if (i == 0)
            temp = 1;
        else
            temp = (temp % k) * (arr[i - 1] % k);
        ans[i] = temp;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            temp = 1;
        } else {
            temp = (temp % k) * (arr[i + 1] % k);
        }
        ans[i] = (ans[i] % k) * (temp % k);
    }
    for (int i = 0; i < n; i++)
        printf("%lld ", ans[i] % k);
    return 0;
}
