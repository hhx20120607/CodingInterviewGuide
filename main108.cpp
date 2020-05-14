#include<stdio.h>

void print(int i,int n,bool down){
    if(i>n)
        return;
    print(i+1,n,true);
    if(down)
        printf("down\n");
    else
        printf("up\n");
    print(i+1,n,false);
}

int main(){
    int n;
    scanf("%d",&n);
    print(1,n,true);
    return 0;
}
