#include<stdio.h>
#define getchar getchar_unlocked
long long int inline scan()
{
    long long int N = 0;
    char C;
    C=getchar();
    while (C < '0' || C>'9') C=getchar();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N;
}
int main()
{
    long long int t,x,y,z,d,a,n,i;
    t=scan();
    while(t--)
    {
        x=scan();
        y=scan();
        z=scan();
        n=(2*z)/(x+y);
        d=(y-x)/(n-5);
        a=x-2*d;
        printf("%d\n",n);
        for(i=0;i<n;i++)
        {
            printf("%d ",a+i*d);
        }
        printf("\n");
    }
    return 0;
}
