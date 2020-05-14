#include<stdio.h>
#include<stack>

/**
 * 用一个栈实现另一个栈的排序
 * https://www.nowcoder.com/practice/ff8cba64e7894c5582deafa54cca8ff2?tpId=101&tqId=33081&tPage=1&rp=1&ru=%2Fta%2Fprogrammer-code-interview-guide&qru=%2Fta%2Fprogrammer-code-interview-guide%2Fquestion-ranking
 */
using namespace std;

stack<int> stack1, stack2;

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int e;
        scanf("%d", &e);
        stack1.push(e);
    }
    while (!stack1.empty()) {
        int c = stack1.top();
        stack1.pop();
        while (!stack2.empty() && stack2.top() > c) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack2.push(c);
    }
    while (!stack2.empty()) {
        printf("%d ", stack2.top());
        stack2.pop();
    }
    return 0;
}