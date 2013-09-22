#include<stdio.h>
#define MOD 1000007
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
    int t,num;
    long long int ans,n,val1,val2;
    t=scan();
    while(t--)
    {
        num=scan();
        n=num;
        val1=(n*(n+1))%MOD;
        val2=(n*(n-1)/2)%MOD;
        ans=(val1+val2)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
