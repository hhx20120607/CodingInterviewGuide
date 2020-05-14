#include<stdio.h>


/**
一行代码求两个数的最大公约数
https://www.nowcoder.com/practice/731b967dcda845669fee8c41f0b16e8b?tpId=101&tqId=33123&tPage=3&rp=3&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

int fun(int m,int n){
    return n==0?m:fun(n,m%n);
}

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d\n",fun(m,n));
    return 0;
}
