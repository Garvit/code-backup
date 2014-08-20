#include<stdio.h>

int main()
{
    int t,n,i,a;
    long long ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=((long long)n*(n-1))/2;
        printf("%lld\n",ans);
    }
    return 0;
}
