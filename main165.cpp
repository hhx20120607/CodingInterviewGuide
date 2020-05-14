#include <stdio.h>
#include <unistd.h>


int main() {
    for(int i=1;i<100;i++){
        printf("安装进度：%d%%",i);
        fflush(stdout);
        usleep(1000*1000);
        printf("\r");
    }
    return 0;
}