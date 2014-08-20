#include<stdio.h>
#include<math.h>
#define ll long long
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
    int t,l,d,s,c;
    t=scan();
    while(t--)
    {
        l=scan();
        d=scan();
        s=scan();
        c=scan();
        double a=(double)l/s;
        double b=log(a)/log(c+1);
        if(b<=d-1) printf("ALIVE AND KICKING\n");
        else printf("DEAD AND ROTTING\n");
    }
    return 0;
}
