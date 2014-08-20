#include<stdio.h>
#include<math.h>

double area(double a,double b,double c)
{
    double s=(a+b+c)/2,ar;
    ar=sqrt(s*(s-a)*(s-b)*(s-c));
    return ar;
}

int main()
{
    int n,x1,x2,x3,y1,y2,y3,i;
    int mint=1,maxt=1;
    double minarea,maxarea;
    scanf("%d",&n);
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    double a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    double b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    double c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    double ar=area(a,b,c);
    //printf("%f %f %f %lf\n",a,b,c,ar);
    minarea=ar;
    maxarea=ar;
    for(i=2;i<=n;i++)
    {
        scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
        a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
        ar=area(a,b,c);
        if(minarea>=ar)
        {
            minarea=ar;
            mint=i;
        }
        if(maxarea<=ar)
        {
            maxarea=ar;
            maxt=i;
        }
    }
    printf("%d %d\n",mint,maxt);
    return 0;
}
