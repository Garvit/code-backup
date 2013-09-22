#include<stdio.h>

int inline scan()
{
    int N = 0;
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
    int t,n;
    t=scan();
    while(t--)
    {
        n=scan();
        if(n%2==0) printf("%d\n",(n/2+1));
        else printf("%d\n",(n+3)/2);
    }
    return 0;
}
