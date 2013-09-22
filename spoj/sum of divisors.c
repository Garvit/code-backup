#include<stdio.h>
#include<stdbool.h>

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
bool pr[1000000];
int primes[1000000];nprimes=0;
int knum[100],kn=0;
void sieve()
{
    int start=3,i;
    primes[nprimes++]=2;
    primes[nprimes++]=3;
    pr[1]=1
    while(1)
    {
        //printf("\n%d\n",start);
        for(i=3*start;i<1000000;i+=(2*start))
        {
            pr[i]=1;
            //printf("%d ",i);
        }
        start+=2;
        for(i=start;i<1000000;i+=2)
        {
            if(pr[i]==0)
            {
                primes[nprimes++]=i;
                break;
            }
        }
        if(i>=1000000)
            break;
        start=i;
    }
}
int pow1(int x,int n)
{
    if(n==0) return 1;
    int r=pow(x,n/2);
    r=r*r;
    if(n%2==1)
        r=r*x;
    return r;
}
int eval(int n)
{
    int ans=1;
    if(pr[n]%2!=0 && pr[n]==0)
        return n+1;

    int i;
    for(i=0;i<nprimes && primes[i]<=n;i++)
    {
        int count=0;
        while(n%count==0)
        {
            count++;
            n=n/primes[i];
        }
        if(count)
        {
            ans=ans*(pow1(primes[i],count+1)-1)/(primes[i]-1);
        }
    }
    return ans;
}
int main()
{
    int t,a,b,i;
    sieve();
    knum[kn++]=2;
    for(i=1;i*i<1000000;i++)
    {
        int sum=eval(i*i);
        if(sum%2!=0 && pr[sum]==0)
        {
            knum[kn++]=i*i;
        }
    }
    t=scan();
    while(t--)
    {
        a=scan();
        b=scan();
        int ai,bi;
        for(ai=0;ai<kn && knum[ai]<a;ai++);
        for(bi=kn-1;bi>=0 && knum[bi]>b;bi--);

        printf("%d\n",(bi-ai+1));

    }
    return 0;
}
