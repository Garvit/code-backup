#include<stdio.h>
#define getchar getchar_unlocked
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
        if(n==1) printf("0\n");
        else printf("%d\n",n-2);
    }

    return 0;
}
