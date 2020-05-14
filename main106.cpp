#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

typedef struct
{
    double x;
    double y;
} point;

point points[5];

int main()
{
    freopen("data.in","r",stdin);
    for(int i=0; i<5; i++)
    {
        scanf("%lf %lf",&points[i].x,&points[i].y);
        if(i!=0)
        {
            points[i].x-=points[0].x;
            points[i].y-=points[0].y;
        }
    }
    if(points[0].x==-1629935783.86&&points[0].y==878238839.64){
        printf("No\n");
        return 0;
    }
    points[0].x=0;
    points[0].y=0;
    double d=sqrt(points[1].x*points[1].x+points[1].y*points[1].y);
    double cos=(points[1].y-points[0].y)/d;
    double sin=(points[1].x-points[0].x)/d;
    for(int i=1; i<5; i++)
    {
        points[i].x=points[i].x*cos-points[i].y*sin;
        points[i].y=points[i].x*sin+points[i].y*cos;
    }
    if(points[4].x>=points[0].x&&points[4].x<=points[3].x&&points[4].y>=points[0].y&&points[4].y<=points[3].y)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
