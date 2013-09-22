#include<stdio.h>

long long inline scan()
{
    long long N = 0;
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
    long long t,t1,t2,t3,t4;
    double ans;
    t=scan();
    while(t--)
    {
        t1=scan();
        t2=scan();
        t3=scan();
        t4=scan();
        ans=(double)t1/(t1+t2);
        printf("%f\n",ans);

    }

    return 0;
}
