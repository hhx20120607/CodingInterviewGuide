#include<stdio.h>
#include<stack>
#include<string.h>
#include<map>
#define maxn 1010

/**
公式字符串求值（使用后缀表达式实现）
https://www.nowcoder.com/practice/c590e97ee1f6462d871430feee055d25?tpId=101&tqId=33196&tPage=2&rp=2&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

typedef struct
{
    int type; // 0 for operands, 1 for operators
    int value;
    int prio;
} token;

char str[maxn];
token tokens1[maxn];
token tokens2[maxn];
stack<token> stack1;
stack<int> stack2;
map<char,int> map1;

int main()
{
    //freopen("data.in","r",stdin);
    fgets(str,1009,stdin);
    str[strlen(str)-1]='\0';
    int n=strlen(str);
    int j=0;
    int sum=0;
    int sign=1;
    map1['(']=1;
    map1['+']=2;
    map1['-']=2;
    map1['*']=3;
    map1['/']=3;
    map1[')']=4;
    for(int i=0; i<n; i++)
    {
        switch(str[i])
        {
        case '-':
            if(i==0||str[i-1]=='(')
            {
                tokens1[j].type=0;
                tokens1[j].value=-1;
                j++;
                tokens1[j].type=1;
                tokens1[j].value='*';
                tokens1[j].prio=3;
                j++;
                break;
            }
        case '+':
        case '*':
        case '/':
        case '(':
        case ')':
            tokens1[j].type=1;
            tokens1[j].value=str[i];
            tokens1[j].prio=map1[str[i]];
            j++;
            break;
        default:
            sum=sum*10+str[i]-'0';
            if(i==n-1||!(str[i+1]>='0'&&str[i+1]<='9'))
            {
                tokens1[j].type=0;
                tokens1[j].value=sum*sign;
                j++;
                sum=0;
                if(sign==-1)
                    sign=1;
            }
            break;
        }
    }
    int k=0;
    for(int i=0; i<j; i++)
    {
        if(tokens1[i].type==0)
        {
            tokens2[k++]=tokens1[i];
        }
        else
        {
            switch(tokens1[i].value)
            {
            case '(':
                stack1.push(tokens1[i]);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while(!stack1.empty()&&stack1.top().prio>=tokens1[i].prio)
                {
                    tokens2[k++]=stack1.top();
                    stack1.pop();
                }
                stack1.push(tokens1[i]);
                break;
            case ')':
                while(!stack1.empty()&&stack1.top().value!='(')
                {
                    tokens2[k++]=stack1.top();
                    stack1.pop();
                }
                stack1.pop();
                break;
            default:
                break;
            }
        }
    }
    while(!stack1.empty())
    {
        tokens2[k++]=stack1.top();
        stack1.pop();
    }
    for(int i=0; i<k; i++)
    {
        if(tokens2[i].type==0)
        {
            stack2.push(tokens2[i].value);
        }
        else
        {
            int a,b,c;
            a=stack2.top();
            stack2.pop();
            b=stack2.top();
            stack2.pop();
            switch(tokens2[i].value)
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
            stack2.push(c);
        }
    }
    printf("%d\n",stack2.top());
    return 0;
}
