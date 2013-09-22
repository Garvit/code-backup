#include<stdio.h>
#include<math.h>
//#define PI 3.14159265
int main()
{
    int r,n;
    double pi=acos(-1);
    scanf("%d %d",&r,&n);
    while(r!=0 || n!=0)
    {
        double ans=r/sin(pi/(2*n));
        printf("%.2lf\n",ans);
        scanf("%d %d",&r,&n);
    }
    return 0;
}
