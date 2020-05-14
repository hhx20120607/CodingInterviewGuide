#include<stdio.h>

int main(){
    int a;
    scanf("%d",&a);
    int ans=0;
    while(a!=0){
        ans++;
        a-=a&(~a+1);
    }
    printf("%d\n",ans);
    return 0;
}
