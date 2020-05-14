#include <stdio.h>
#include <stack>

/**
 * 如何仅用递归和栈操作逆序一个栈
 * https://www.nowcoder.com/practice/1de82c89cc0e43e9aa6ee8243f4dbefd?tpId=101&tqId=33075&tPage=1&rp=1&ru=%2Fta%2Fprogrammer-code-interview-guide&qru=%2Fta%2Fprogrammer-code-interview-guide%2Fquestion-ranking
 */

using namespace std;

stack<int> stack1;

int removeBottom(stack<int>* stack1){
    int t=stack1->top();
    stack1->pop();
    if(stack1->empty())
        return t;
    else{
        int r=removeBottom(stack1);
        stack1->push(t);
        return r;
    }
}

void reverse(stack<int>* stack1){
    if(stack1==NULL||stack1->empty())
        return;
    int b=removeBottom(stack1);
    reverse(stack1);
    printf("%d ",b);
    stack1->push(b);
}

int main(){
    freopen("data.in","r",stdin);
    int n;
    scanf("%d",&n);
    while(n>0){
        int c;
        scanf("%d",&c);
        stack1.push(c);
        n--;
    }
    reverse(&stack1);
    return 0;
}
