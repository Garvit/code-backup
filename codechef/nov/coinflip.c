#include<stdio.h>
int inline scan()
{
    int N = 0;
    char C;
    C=getchar_unlocked();
    while (C < '0' || C>'9') C=getchar_unlocked();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar_unlocked();
    }

    return N;
}
int main()
{
    int t,g,n;
    char i,q;
    t=scan();
    while(t--)
    {
        g=scan();
        while(g--)
        {
            i=getchar();
            n=scan();
            q=getchar();

            printf("%d\n",((i==q)?0:(n%2))+(n>>1));

            getchar();
        }
    }
    return 0;
}
