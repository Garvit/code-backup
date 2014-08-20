#include<stdio.h>
int main()
{
    int t,n,a,i;
    long long ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a);

        ans=((long long)n*(n-1))/2;
        printf("%lld\n",ans);
    }
    return 0;
}
