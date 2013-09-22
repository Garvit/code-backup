#include<stdio.h>

int inline scan()
{
    int N = 0;
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
    int cases,n;
    long long ans=0,t;
    cases=scan();
    while(cases--)
    {
        n=scan();
        ans=0;
        t=(n-1)/3;
        ans=(t*(6+3*(t-1)))/2;
        t=(n-1)/5;
        ans+=(t*(10+5*(t-1)))/2;
        t=(n-1)/15;
        ans-=(t*(30+15*(t-1)))/2;
        printf("%lld\n",ans);

    }
}
