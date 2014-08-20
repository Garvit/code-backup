// n^m - 2(n-1)^m + (n-2)^m
#include<stdio.h>
#define MOD 1000000007
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

long long power(long long base,long long exp)
{
    long long result=1;
    if(base==0) return 0;
    if(base==1) return 1;
    while(exp>0)
    {
        if(exp%2==1)
            result=(result*base) % MOD;
        exp=exp>>1;
        base=(base*base)%MOD;
    }
    return result;
}

int main()
{
    int t,i,n,m,q,k;
    t=scan();
    while(t--)
    {
        n=scan();
        m=scan();
        q=scan();
        k=scan();
        long long ans;
        if(m<=q) ans=0;
        else
        {
            ans=(power(q+1,n)+power(q-1,n)-(2*power(q,n))%MOD)%MOD;
            if(ans<0) ans+=MOD;
            ans=((m-q)*ans)%MOD;
        }
        printf("%lld\n",ans);

    }
    return 0;
}
