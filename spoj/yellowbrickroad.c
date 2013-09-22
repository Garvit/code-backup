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
int hcf(int a,int b)
{
    int max=a>b?a:b;
    int min=a<b?a:b;
    int rem=max%min;
    while(rem!=0)
    {
        max=min;
        min=rem;
        rem=max%min;
    }
    return min;
}
int len[1000];
int wid[1000];
int hei[1000];
int main()
{
    int n,g,i;
    long long int ans=0;
    while((n=scan())!=0)
    {
        ans=0;
        len[0]=scan();
        wid[0]=scan();
        hei[0]=scan();
        int gcd=hcf(hcf(len[0],wid[0]),hei[0]);

        for(i=1;i<n;i++)
        {
            len[1]=scan();
            wid[1]=scan();
            hei[1]=scan();
            g=hcf(hcf(len[i],wid[i]),hei[i]);
            gcd=hcf(gcd,g);
        }
        for(i=0;i<n;i++)
        {
            ans+=(len[i]/gcd * wid[i]/gcd * hei[i]/gcd);
        }
        printf("%lld\n",ans);

    }
    return 0;
}
