#include<stdio.h>
int inline scan()
{
    int N = 0,sign=1;
    char C;
    C=getchar();
    while ((C < '0' || C>'9') && C!='-') C=getchar();
    if(C=='-'){ sign=-1; C=getchar(); }
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N*sign;
}

int main()
{
    int t,n,z,val;
    long long int ans=1,en;
    t=scan();
    for(z=1;z<=t;z++)
    {
        ans=1;en=1;
        n=scan();
        while(n--)
        {
            val=scan();
            en+=val;
            if(en<=0)
            {
              ans+=1-en;
              en=1;
            }
        }
        printf("Scenario #%d: %lld\n",z,ans);

    }
    return 0;
}
