#include<stdio.h>
#include<math.h>
#include<algorithm>

using namespace std;

typedef struct
{
    double x;
    double y;
} point;

point points[4],vectors[3];
double ans[3];

double multiply(point a,point b)
{
    return b.y*a.x-b.x*a.y;
}

int main()
{
    freopen("data.in","r",stdin);
    for(int i=0; i<4; i++)
    {
        scanf("%lf %lf",&points[i].x,&points[i].y);
    }
    for(int i=0; i<3; i++)
    {
        if(i!=2)
        {
            vectors[i].x=points[i+1].x-points[i].x;
            vectors[i].y=points[i+1].y-points[i].y;
        }
        else
        {
            vectors[i].x=points[0].x-points[i].x;
            vectors[i].y=points[0].y-points[i].y;
        }
    }
    for(int i=0;i<3;i++){
        point t={points[3].x-points[i].x,points[3].y-points[i].y};
        ans[i]=multiply(vectors[i],t);
    }
    if(ans[0]*ans[1]>=0&&ans[1]*ans[2]>=0)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
