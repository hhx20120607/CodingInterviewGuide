#include<stdio.h>
#include<stdlib.h>

/**
数组中未出现的最小正整数
**/

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int l = 0, r = n;
    int i = 0;
    while (i < r) {
        if (arr[i] == l + 1) {
            l++;
            i++;
        } else if (arr[i] <= l || arr[i] > r) {
            r--;
            arr[i] = arr[r - 1];
        } else if (arr[arr[i] - 1] == arr[i]) {
            r--;
            arr[i] = arr[r - 1];
        } else {
            int t = arr[i];
            arr[i] = arr[arr[i] - 1];
            arr[t - 1] = t;
        }
    }
    printf("%d\n", i + 1);
    return 0;
}
