#include<stdio.h>
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
int main()
{
    int t,n,i;
    long long ans=0,d=power(2,MOD-2),den;
    scanf("%d",&t);
    while(t--)
    {
        ans=1;
        scanf("%d",&n);
        den=power(d,n);
        for(i=1;i<=2*n;i++)
        {
            ans=(ans*i)%MOD;
        }
        ans=(ans*den)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}
