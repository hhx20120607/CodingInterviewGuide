#include <stdio.h>
#include <queue>
#include <malloc.h>

/**
 * 最大值减去最小值小于或等于num的子数组数量
 * https://www.nowcoder.com/practice/5fe02eb175974e18b9a546812a17428e?tpId=101&tqId=33086&tPage=1&rp=1&ru=%2Fta%2Fprogrammer-code-interview-guide&qru=%2Fta%2Fprogrammer-code-interview-guide%2Fquestion-ranking
 */

using namespace std;

deque<int> queue1, queue2;

int main() {
    freopen("data.in", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int i = 0, j = 0;
    int ans = 0;
    while (i < n) {
        while (j < n) {
            while (!queue1.empty() && arr[queue1.back()] >= arr[j])
                queue1.pop_back();
            queue1.push_back(j);
            while (!queue2.empty() && arr[queue2.back()] <= arr[j])
                queue2.pop_back();
            queue2.push_back(j);
            if (arr[queue2.front()] - arr[queue1.front()] > k)
                break;
            j++;
        }
        ans += j - i;
        if (queue1.front() == i)
            queue1.pop_front();
        if (queue2.front() == i)
            queue2.pop_front();
        i++;
    }
    printf("%d", ans);
    return 0;
}