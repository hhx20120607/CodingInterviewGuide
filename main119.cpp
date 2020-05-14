#include<stdio.h>
#include <limits.h>

/**
 * 判断一个数是否是回文数
 * @return
 */

int main() {
    freopen("data.in", "r", stdin);
    int n;
    scanf("%d",&n);
    if(n==INT_MIN){
        printf("No\n");
        return 0;
    }
    if(n<0)
        n=-n;
    int m=1;
    while(m*10<=n)
        m*=10;
    int p=n,q=n;
    while(m!=1){
        if(p/m!=q%10){
            printf("No\n");
            return 0;
        }
        else{
            p=p%m;
            q=q/10;
            m=m/10;
        }
    }
    printf("Yes\n");
    return 0;
}
