#include<stdio.h>

#define MOD 109546051211LL
#define ll long long


int main()
{
    int n,i;
    ll ans=1,fact=1;
    fact=(39087753683LL*209)%MOD;
    ans=(282977660661LL*fact)%MOD;
    /*scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        fact=(fact*i)%109546051211LL;
        ans=(ans*fact)%109546051211LL;
    }*/
    printf("%lld %lld",ans,fact);
    return 0;
}
