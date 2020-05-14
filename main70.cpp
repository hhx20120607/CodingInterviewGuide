#include<stdio.h>

/**
不用额外变量交换两个整数得值
https://www.nowcoder.com/practice/1827258942284b2abfe65809785ac91a?tpId=101&tqId=33210&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    a=a^b;
    b=a^b;
    a=a^b;
    printf("%d %d\n",a,b);
    return 0;
}
