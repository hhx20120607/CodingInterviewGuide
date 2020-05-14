#include<stdio.h>
#include<stdlib.h>

double get0To1(){
    return rand()*1.0/(RAND_MAX+1);
}

double get(int k){
    double ans;
    for(int i=0;i<k;i++){
        if(i==0)
            ans=get0To1();
        else{
            double t=get0To1();
            if(t>ans)
                ans=t;
        }
    }
    return ans;
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%lf\n",get(n));
    return 0;
}
