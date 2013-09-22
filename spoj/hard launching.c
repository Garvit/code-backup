#include<stdio.h>
#include<math.h>
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
    int t,d,v,z;
    double a,ans,pi=180/(2*acos(0.0));
    t=scan();
    for(z=1;z<=t;z++)
    {
        d=scan();
        v=scan();
        a=d*9.806/(v*v);
        if(a>1) printf("Scenario #%d: -1\n",z);
        else
        {
            ans=asin(a)/2 * pi;
            printf("Scenario #%d: %.2f\n",z,ans);
        }
    }
    return 0;
}
