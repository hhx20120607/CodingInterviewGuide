#include<stdio.h>
#include<stack>
#include <malloc.h>
#include <cstring>
#include <stdlib.h>

/**
 * 由两个栈组成的队列
 * https://www.nowcoder.com/practice/6bc058b32ee54a5fa18c62f29bae9863?tpId=101&tqId=33074&tPage=1&rp=1&ru=%2Fta%2Fprogrammer-code-interview-guide&qru=%2Fta%2Fprogrammer-code-interview-guide%2Fquestion-ranking
 */

using namespace std;

stack<int> stack1, stack2;

void add(int e) {
    stack1.push(e);
}

int remove() {
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    if (!stack2.empty()){
        int t=stack2.top();
        stack2.pop();
        return t;
    }
    exit(1);
}

int element() {
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    if (!stack2.empty())
        return stack2.top();
    exit(1);
}

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d", &n);
    char *o = (char *) malloc(sizeof(char) * 5);
    for (int i = 0; i < n; i++) {
        scanf("%s", o);
        if (strcmp(o, "add") == 0) {
            int e;
            scanf("%d", &e);
            add(e);
        } else if (strcmp(o, "peek") == 0)
            printf("%d\n", element());
        else
            remove();
    }
    return 0;
}