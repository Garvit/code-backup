#include<stdio.h>

long long inline scan()
{
    long long N = 0;
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
    long long t,n,x,cards,items;
    t=scan();
    while(t--)
    {
        x=scan();
        n=scan();
        cards=items=x;
        while(cards>=n)
        {
            items+=cards/n;
            cards=cards/n+cards%n;
        }
        printf("%lld\n",items);
    }
    return 0;
}
