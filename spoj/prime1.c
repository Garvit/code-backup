#include<stdio.h>
#include<stdbool.h>
#include<string.h>
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
bool pr[32000];
bool arr[100001];
void sieve()
{
    int start=3,i;

    while(1)
    {
        //printf("\n%d\n",start);
        for(i=3*start;i<32000;i+=(2*start))
        {
            pr[i]=1;
            //printf("%d ",i);
        }
        start+=2;
        for(i=start;i<32000;i+=2)
        {
            if(pr[i]==0)
            {
                break;
            }
        }
        if(i>=32000)
            break;
        start=i;
    }
}
int main()
{
    int t,m,n,start;
    long long int i;
    sieve();
    t=scan();
    while(t--)
    {
        m=scan();
        n=scan();
        for(i=3;i<32000 && i<=n;i+=2)
        {
            if(pr[i]==0)
            {
                start=m/i;
                if(m!=start*i) start++;
                if(start<=1)
                    start=2;
                while(i*start <=n)
                {
                    arr[i*start-m]=1;
                    start++;
                }
            }
        }
        if(m<=2)
          {
             printf("2\n"); start=3;
          }
        else start=(m%2==0)?m+1:m;
        for(i=start;i<=n;i+=2)
        {
            if(arr[i-m]==0)
            {
                printf("%lld\n",i);
            }
        }
        printf("\n");
        memset(arr,0,sizeof(arr));

    }
    return 0;
}
