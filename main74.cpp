#include<stdio.h>
#include<stdlib.h>

void fun1()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d",&a);
        ans=ans^a;
    }
    printf("%d\n",ans);
}


void fun2(){
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    int a=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        a=a^arr[i];
    }
    a=a&(~a+1);
    int b=0,c=0;
    for(int i=0;i<n;i++){
        if((arr[i]&a)!=0)
            b=b^arr[i];
        else
            c=c^arr[i];
    }
    printf("%d %d\n",b,c);
}

int main()
{
    freopen("data.in","r",stdin);
    fun2();
    return 0;
}
