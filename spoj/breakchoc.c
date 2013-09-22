#include<stdio.h>

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
int logbase2(long long int x)
{
    if(x==1) return 0;
    int i=1,f=2;
    while(f<x)
    {
        i++;
        f*=2;
    }
    return i;
}
int main()
{
    int t,z;
    long long int n,m,k,ans1,ans2;
    t=scan();
    for(z=1;z<=t;z++)
    {
        //scanf("%lld%lld%lld",&n,&m,&k);
        n=scan();
        m=scan();
        k=scan();
        ans1=n*m*k-1;
        ans2=logbase2(n)+logbase2(m)+logbase2(k);
        printf("Case #%d: %lld %lld\n",z,ans1,ans2);
    }
    return 0;
}
