#include<stdio.h>
#define MAX 10001
long long inline scan()
{
    long long N = 0;
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

long long mem[MAX];
void eval()
{
    long long a,b,l,ans,i;
    mem[4]=2;
    for(i=5;i<MAX;i++)
    {
        b=i/2;
        a=i/2 * (i/2-1)*(i/2+4);
        a/=6;
        l=i-1-i/2;
        ans=l*(l-1)*(l+4);
        ans/=6;
        ans*=b;
        ans+=l*a;
        mem[i]=ans;

    }
}

int main()
{
    long long t,k;
    int l,r,mid;
    eval();
    t=scan();
    while(t--)
    {
        k=scan();
        l=4;r=10000;
        mid=(l+r)/2;
        while(l<r)
        {
            if(mem[mid]<k)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
            mid=(l+r)/2;
            //printf("%d %d\n",l,r);
        }
        printf("%d\n",l);

    }
}
