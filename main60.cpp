#include<stdio.h>
#include<stack>
#include<string.h>
#include<map>
#define maxn 1010

/**
公式字符串求值（使用中缀表达式实现）
https://www.nowcoder.com/practice/c590e97ee1f6462d871430feee055d25?tpId=101&tqId=33196&tPage=2&rp=2&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

typedef struct
{
    int type; // 0 for operands, 1 for operators
    int value;
} token;

char str[maxn];
token tokens[maxn];
stack<int> stack1;
stack<char> stack2;
map<char,int> map1;

void calculate()
{
    int a=stack1.top();
    stack1.pop();
    int b=stack1.top();
    stack1.pop();
    int c;
    switch(stack2.top())
    {
    case '+':
        c=b+a;
        break;
    case '-':
        c=b-a;
        break;
    case '*':
        c=b*a;
        break;
    case '/':
        c=b/a;
        break;
    default:
        break;
    }
    stack2.pop();
    stack1.push(c);
}

int main()
{
    freopen("data.in","r",stdin);
    fgets(str,1009,stdin);
    str[strlen(str)-1]='\0';
    int n=strlen(str);
    int j=0;
    int sum=0;
    int sign=1;
    map1['(']=1;
    map1[')']=1;
    map1['+']=2;
    map1['-']=2;
    map1['*']=3;
    map1['/']=3;
    for(int i=0; i<n; i++)
    {
        switch(str[i])
        {
        case '-':
            if(i==0||str[i-1]=='(')
            {
                tokens[j].type=0;
                tokens[j].value=-1;
                j++;
                tokens[j].type=1;
                tokens[j].value='*';
                j++;
                break;
            }
        case '+':
        case '*':
        case '/':
        case '(':
        case ')':
            tokens[j].type=1;
            tokens[j].value=str[i];
            j++;
            break;
        default:
            sum=sum*10+str[i]-'0';
            if(i==n-1||!(str[i+1]>='0'&&str[i+1]<='9'))
            {
                tokens[j].type=0;
                tokens[j].value=sum*sign;
                j++;
                sum=0;
                if(sign==-1)
                    sign=1;
            }
            break;
        }
    }
    for(int i=0; i<j; i++)
    {
        if(tokens[i].type==0)
        {
            stack1.push(tokens[i].value);
        }
        else
        {
            if(tokens[i].value=='(')
            {
                stack2.push('(');
            }
            else
            {
                while(!stack2.empty()&&stack2.top()!='('&&map1[stack2.top()]>=map1[tokens[i].value])
                {
                    calculate();
                }
                stack2.push(tokens[i].value);
                if(stack2.top()==')'){
                    stack2.pop();
                    stack2.pop();
                }
            }
        }
    }
    while(!stack2.empty()){
        calculate();
    }
    printf("%d\n",stack1.top());
    return 0;
}
