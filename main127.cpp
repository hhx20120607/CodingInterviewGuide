#include<stdio.h>
#include<malloc.h>

/**
 * 在两个长度相等的排序数组中找到上中位数
 * @return
 */

int main() {
    freopen("data.in","r",stdin);
    int n;
    scanf("%d", &n);
    int* arr1 = (int*) malloc(sizeof(int) * n);
    int* arr2 = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr2[i]);
    int s1 = 0, e1 = n - 1, s2 = 0, e2 = n - 1;
    while (s1 < e1) {
        int m1 = (s1 + e1) / 2;
        int m2 = (s2 + e2) / 2;
        if (arr1[m1] == arr2[m2]) {
            printf("%d\n", arr1[m1]);
            return 0;
        } else if (arr1[m1] > arr2[m2]) {
            if ((e1 - s1 + 1) % 2 == 0) {
                e1 = m1;
                s2 = m2 + 1;
            } else {
                e1 = m1;
                s2 = m2;
            }
        } else {
            if ((e1 - s1 + 1) % 2 == 0) {
                e2 = m2;
                s1 = m1 + 1;
            } else {
                e2 = m2;
                s1 = m1;
            }
        }
    }
    if (arr1[s1] < arr2[s2])
        printf("%d\n", arr1[s1]);
    else
        printf("%d\n", arr2[s2]);
    return 0;
}