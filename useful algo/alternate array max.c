#include<stdio.h>


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
long long arr[1000];
long long max(int n)
{
    long long inc=arr[0],exc=0,excn=0,i;
    for(i=1;i<n;i++)
    {
        excn=inc>exc?inc:exc;
        inc=exc+arr[i];
        exc=excn;
    }
    return inc>exc?inc:exc;
}
int main()
{
    long long t,z,i,n;
    t=scan();
    for(z=1;z<=t;z++)
    {
        n=scan();
        if(n==0)
        {
            printf("Case %lld: 0\n",z);
            continue;
        }
        for(i=0;i<n;i++)
        {
            arr[i]=scan();
        }
        printf("Case %lld: %lld\n",z,max(n));

    }
    return 0;
}


