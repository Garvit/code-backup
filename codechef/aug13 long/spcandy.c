#include<stdio.h>
#define ll long long

ll inline scan()
{
    ll  N = 0;
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
    ll t,n,k;
    t=scan();
    while(t--)
    {
        n=scan();
        k=scan();
        if(k!=0)
            printf("%lld %lld\n",n/k,n%k);
        else
            printf("0 %lld\n",n);
    }
    return 0;
}
