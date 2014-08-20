#include<stdio.h>

void func(long long n,long long num,long long c)
{
    if(n==1)
    {
        if(num<c/2) printf("Hacker\n");
        else printf("Earth\n");
        return;
    }
    if(num<c/2)
    {
        func(n-1,num,c/2);
    }
    else
        func(n-1,num-c/2,c/2);

}
int main()
{
    int t,i;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        long long c=2;
        for(i=1;;i++)
        {
            if(n<=c*i) break;
            n-=c*i;
            c=c*2;
        }
        long long num=(n-1)/i;
        n-=(num*i);
        func(n,num,c);
    }
    return 0;
}
