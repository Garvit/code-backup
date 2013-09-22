#include<stdio.h>
#define ll long long

ll inline scan()
{
    ll N = 0;
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
    ll d,f,b,m,plots,req,limit;
    d=scan();
    f=scan();
    b=scan();
    m=scan();

    while(d!=0)
    {
        plots=1+f*(f+1)/2;
        req=plots*b;
        limit=d-m;
        if(req<=limit)
        {
            printf("Farmer Cream will have %lld Bsf to spend.\n",d-req);
        }
        else
        {
            printf("The firm is trying to bankrupt Farmer Cream by %lld Bsf.\n",req-limit);
        }
        d=scan();
        f=scan();
        b=scan();
        m=scan();

    }
    return 0;
}
