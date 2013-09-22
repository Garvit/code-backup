#include<stdio.h>

int inline scan()
{
    int N = 0,f=0;
    char C;
    C=getchar();
    while ((C < '0' || C>'9') && C!='-') C=getchar();
    if(C=='-')
    {
        f=1;
        C=getchar();
    }
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return f?(-N):N;
}

int main()
{
    int t=scan();
    printf("%d",t);
    return 0;
}
