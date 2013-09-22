#include<stdio.h>
#define MOD 10000007ll
#define getchar getchar_unlocked
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
    while(exp>0)
    {
        if(exp%2==1)
            result=(result*base) % MOD;
        exp=exp>>1;

        base=(base*base)%MOD;
        //printf("%lld\n",result);

    }
    return result;
}
int main()
{
    int n,k,ans;
    while(1)
    {
        n=scan();
        k=scan();
        if(n==0) break;

        ans=((2*power(n-1,k))%MOD + power(n,k) + power(n,n) + (2*power(n-1,n-1))%MOD)%MOD;
        printf("%d\n",ans);
    }
    return 0;
}
