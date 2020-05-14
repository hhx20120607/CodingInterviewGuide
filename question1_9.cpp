#include <stdio.h>
#include <stack>
#include <malloc.h>
#include <cstring>

/**
 * 求最大子矩阵的大小
 * https://www.nowcoder.com/practice/ed610b2fea854791b7827e3111431056?tpId=101&tqId=33084&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
 */

using namespace std;

stack<int> stack1;

int main() {
    freopen("data.in", "r", stdin);
    int m, n;
    scanf("%d%d", &m, &n);
    int **arr = (int **) malloc(sizeof(int *) * m);
    int *temp = (int *) malloc(sizeof(int) * n);
    int *left = (int *) malloc(sizeof(int) * n);
    int *right = (int *) malloc(sizeof(int) * n);
    memset(temp, 0, sizeof(int) * n);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        arr[i] = (int *) malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
            temp[j] = arr[i][j] == 0 ? 0 : temp[j] + 1;
        }
        for (int j = 0; j < n; j++) {
            while (!stack1.empty() && temp[stack1.top()] >= temp[j])
                stack1.pop();
            if (!stack1.empty())
                left[j] = stack1.top();
            else
                left[j] = -1;
            stack1.push(j);
        }
        while (!stack1.empty())
            stack1.pop();
        for (int j = n - 1; j >= 0; j--) {
            while (!stack1.empty() && temp[stack1.top()] >= temp[j])
                stack1.pop();
            if (!stack1.empty())
                right[j] = stack1.top();
            else
                right[j] = -1;
            stack1.push(j);
        }
        while (!stack1.empty())
            stack1.pop();
        for (int j = 0; j < n; j++) {
            int cur = (right[j] - left[j] - 1) * temp[j];
            if (cur > ans)
                ans = cur;
        }
    }
    printf("%d", ans);
    return 0;
}