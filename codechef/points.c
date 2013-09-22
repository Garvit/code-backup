#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct coord
{
    int x,y;
}coord;

coord* points;
int inline scan()
{
    int N = 0;
    char C;
    C=getchar_unlocked();
    while (C < '0' || C>'9') C=getchar_unlocked();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar_unlocked();
    }

    return N;
}
int compare(const void* elem1,const void* elem2)
{
    coord* p1=(coord*)elem1;
    coord* p2=(coord*)elem2;
    if(p1->x < p2->x)
        return -1;
    else if(p1->x > p2->x)
         return 1;
    else
    {
        if(p1->y > p2->y)
            return -1;
        else if(p1->y < p2->y)
                return 1;
        else
            return 0;
    }
}
int main()
{
    int t,n,x,y,i;
    double ans;
    t=scan();
    while(t--)
    {
        n=scan();
        ans=0;
        points=malloc(n*sizeof(coord));
        for(i=0;i<n;i++)
        {
            x=scan();
            y=scan();
            points[i].x=x;
            points[i].y=y;
        }
        qsort(points,n,sizeof(coord),compare);
        for(i=0;i<n-1;i++)
        {
            ans+=sqrt(pow(fabs(points[i+1].x-points[i].x),2)+pow(fabs(points[i+1].y-points[i].y),2));
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
