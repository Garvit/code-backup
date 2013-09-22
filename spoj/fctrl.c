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
    int t,n,ans;
    t=scan();
    while(t--)
    {
        n=scan();
        ans=0;
        while(n!=0)
        {
            n=n/5;
            ans+=n;

        }
        printf("%d\n",ans);

    }
    return 0;
}
