#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<algorithm>

/**
 * ��Ŀ�����������ĳ���
 */
using namespace std;

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        int s = INT_MAX;
        int b = INT_MIN;
        for (int j = i; j >= 0; j--) {
            s = min(s, arr[j]);
            b = max(b, arr[j]);
            int dif = i - j;
            if (dif == b - s && dif + 1 > ans)
                ans = dif + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
