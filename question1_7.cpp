#include <stdio.h>
#include <malloc.h>
#include <queue>
#include <limits.h>

/**
 * 生成窗口的最大值数组
 * https://www.nowcoder.com/practice/b316c7f9617744b98fa311ae29ac516c?tpId=101&tqId=33083&tPage=1&rp=1&ru=%2Fta%2Fprogrammer-code-interview-guide&qru=%2Fta%2Fprogrammer-code-interview-guide%2Fquestion-ranking
 */

using namespace std;

deque<int> deque1;

int main() {
    freopen("data.in", "r", stdin);
    int n, w;
    scanf("%d%d", &n, &w);
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        while (!deque1.empty() && arr[deque1.back()] <= arr[i])
            deque1.pop_back();
        deque1.push_back(i);
        if (i >= w - 1) {
            while (!deque1.empty() && deque1.front() < i-w+1)
                deque1.pop_front();
            printf("%d ", arr[deque1.front()]);
        }
    }
    return 0;
}