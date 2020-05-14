#include<stdio.h>
#include<stack>
#include <malloc.h>
#include <cstring>

/**
 * 设计一个有getMin功能的栈
 * https://www.nowcoder.com/practice/05e57ce2cd8e4a1eae8c3b0a7e9886be?tpId=101&tqId=33073&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
 */

using namespace std;

typedef struct {
    int val;
    int min;
} node;

stack<node> stack1;

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    char *o = (char *) malloc(sizeof(char) * 7);
    int e;
    while (n > 0) {
        scanf("%s %d", o, &e);
        if (strcmp(o, "push") == 0) {
            node t = {e, e};
            if (!stack1.empty() && stack1.top().min < t.min)
                t.min = stack1.top().min;
            stack1.push(t);
        } else if (strcmp(o, "pop") == 0) {
            if (!stack1.empty())
                stack1.pop();
        } else {
            printf("%d\n", stack1.top().min);
        }
        n--;
    }
    free(o);
    return 0;
}