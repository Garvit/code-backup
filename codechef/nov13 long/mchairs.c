#include<stdio.h>
#define MOD 1000000007

long long int power(long long int exp)
{
    long long int result=1,base=2;

    while(exp>0)
    {
        if(exp&1)
            result=(result*base) % MOD;
        exp=exp>>1;
        base=(base*base)%MOD;

    }
    return result;


}
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
    int t,n,i;
    t=scan();
    while(t--)
    {
        n=scan();
        long long ans=power(n);
        ans=ans-1;
        if(ans<0) ans=+MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
