#include<stdio.h>

/**
不用任何比较判断找出两个数中较大的数
https://www.nowcoder.com/practice/02ae5ccb63064bbdb2366417d8b70ff3?tpId=101&tqId=33211&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
**/

int flip(int c){
    return c^1;
}

int getSign(int c){
    return flip((c>>31)&1);
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int c=a-b;
    int signC=getSign(c);
    int signA=getSign(a);
    int signB=getSign(b);
    int same=flip(signA^signB);
    int diff=flip(same);
    int ans=a*(diff*signA+same*signC)+b*(diff*(1-signA)+same*(1-signC));
    printf("%d\n",ans);
    return 0;
}
