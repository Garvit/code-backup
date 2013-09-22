#include<stdio.h>

unsigned long long int coins(unsigned long long int n)
{
    if(n<12)
        return n;
    unsigned long long int t;
    t=coins(n/2)+coins(n/3)+coins(n/4);
    return t>n?t:n;
}
int main()
{
    int t;
    unsigned long long int n,ans=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu",&n);


        ans=coins(n);

        printf("%llu\n",ans);
    }
    return 0;
}
