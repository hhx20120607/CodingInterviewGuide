#include<stdio.h>
#include <malloc.h>

/**
 * 分糖果问题
 * @return
 */

void fun1() {
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    long long sum = 1, pre = 1, cnt = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            sum += pre + 1;
            pre++;
        } else if (arr[i] == arr[i - 1])
            sum += pre;
        else {
            cnt++;
            if (i == n - 1 || arr[i + 1] >= arr[i]) {
                sum += cnt * (cnt + 1) / 2;
                if (pre < cnt + 1)
                    sum += cnt + 1 - pre;
                pre = 1;
                cnt = 0;
            }
        }
    }
    printf("%lld\n", sum);
}

void fun2() {
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    long long sum = 1, pre = 1, cnt = 0, sme = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            sum += pre + 1;
            pre++;
            sme = 1;
        } else if (arr[i] == arr[i - 1]) {
            sum += pre;
            sme++;
        } else {
            cnt++;
            if (i == n - 1 || arr[i + 1] >= arr[i]) {
                sum += cnt * (cnt + 1) / 2;
                if (pre < cnt + 1)
                    sum += (cnt + 1 - pre) * sme;
                pre = 1;
                cnt = 0;
                sme = 1;
            }
        }
    }
    printf("%lld\n", sum);
}

int main() {
    freopen("data.in", "r", stdin);
    fun2();
    return 0;
}