#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MOD 1000000007

long long int power(long long int base,long long int exp)
{
    long long int result=1;
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
int main() {

    int t,m,n,k;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        long long ans=1,den=1,i;
        for(i=m+n-2;i>m-1;i--)
        {
            ans=(ans*i)%MOD;
        }
        for(i=1;i<=n-1;i++)
        {
            den=(den*i)%MOD;
        }
        ans=(ans*power(den,MOD-2))%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}

