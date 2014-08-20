#include<stdio.h>

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int n,m,i,j,x,y,z,p,a,b;
    scanf("%d %d %d %d %d %d",&n,&m,&x,&y,&z,&p);
    x=x%4;
    y=y%2;
    z=z%4;
    int a1,b1,n1,m1;
    for(i=0;i<p;i++)
    {
        n1=n;m1=m;
        scanf("%d %d",&a,&b);
        for(j=1;j<=x;j++)
        {
            b1=n1-a+1;
            a1=b;
            swap(&n1,&m1);
            a=a1;b=b1;
            //printf("%d %d\n",n1,m1);
        }
        if(y==1)
        {
            b=m1-b+1;
        }
        //printf("%d %d\n",a,b);
        for(j=1;j<=z;j++)
        {
            b1=a;
            a1=m1-b+1;
            swap(&n1,&m1);
            a=a1;b=b1;
            //printf("%d %d\n",n1,m1);
        }
        printf("%d %d\n",a,b);
    }
}
