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

int sum[1000001];
short int order[1000001];
int cumulative[12][1000001];
void seive()
{
    int i,j;
    for(i=2;i<=500000;i++)
    {
        if(sum[i]==0)
        {
            for(j=2*i;j<=1000000;j+=i)
            {
                sum[j]+=i;
            }
        }
    }
    for(i=2;i<=1000000;i++)
    {
        if(sum[i]==0) order[i]=1;
        else order[i]=order[sum[i]]+1;
    }
    for(i=0;i<12;i++)
    {
        for(j=2;j<=1000000;j++)
        {
            cumulative[i][j]=cumulative[i][j-1];
            if(order[j]==i+1) cumulative[i][j]++;
        }
    }

}

int main()
{
    seive();
    int p,a,b,k,ans;
    p=scan();
    while(p--)
    {
        a=scan();
        b=scan();
        k=scan();
        if(k>12) ans=0;
        else
            ans=cumulative[k-1][b]-cumulative[k-1][a-1];

        printf("%d\n",ans);
    }
    return 0;
}
