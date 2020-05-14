#include<stdio.h>
#include<algorithm>

/**
有关阶乘的两个问题
https://www.nowcoder.com/practice/a54d454f00f84dc3a6eeaec7a7233d51?tpId=101&tqId=33124&rp=3&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
https://www.nowcoder.com/practice/29f6e99322044050ae7c37756581c0c1?tpId=101&tqId=33125&rp=3&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

using namespace std;

void fun1(){
    long long n;
    scanf("%lld",&n);
    long long s=0;
    long long k=5;
    while(n>=k){
        s+=n/k;
        k*=5;
    }
    printf("%lld\n",s);
}

void fun2(){
    long long n;
    scanf("%lld",&n);
    long long s=0;
    long long k=2;
    while(n>=k){
        s+=n/k;
        k*=2;
    }
    printf("%lld\n",s);
}

int main()
{
    fun2();
    return 0;
}
