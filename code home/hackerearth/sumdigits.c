#include<stdio.h>
#include<string.h>

long long total[16][11][140];
int numd(long long n)
{
    int d=0;
    while(n>0)
    {
        d++;
        n=n/10;
    }
    return d;
}
int main()
{
    long long a,b,prev;
    int s,i,j,sum;
    scanf("%lld %lld %d",&a,&b,&s);
    int t=numd(b);
    printf("%d",t);
    total[1][1][1]=1
    for(i=1;i<=t;i++)
    {
        for(j=1;j<=9;j++)
        {
            for(sum=0;sum<=(i-1)*9;sum++)
            {
                total[i][j][sum+j]+=total[i][j-1][sum+j]+total[i-1][9][sum];
            }
        }

    }
    for(i=numd(a)+1;i<t;i++)
    {
        printf("%lld\n",total[i][9][s]);
    }
}
