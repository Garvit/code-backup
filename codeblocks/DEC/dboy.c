#include<stdio.h>

int h[500];
int k[500];
int dp[1010];

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
int find(int x,int n)
{
    if(x==0)
        return 0;
    if(dp[x]!=0)
    {
          return dp[x];
    }
    int q=1000,temp,j;
    for(j=0;j<n;j++)
    {
        if(k[j]<=x)
        {
            temp=1+find(x-k[j],n);
            if(temp < q)
            {
                q=temp;
            }
        }
        //printf("%d %d %d \n",x,k[j],q);
    }
    dp[x]=q;
    return q;
}
int main()
{
    int t,i,sum,n;
    t=scan();
    while(t--)
    {
        sum=0;
        n=scan();
        for(i=0;i<n;i++)
        {
            h[i]=scan();
            h[i]*=2;
        }
        for(i=0;i<n;i++)
        {
            k[i]=scan();
        }
        for(i=0;i<n;i++)
        {
            //printf("%d:- %d \n",h[i],find(h[i]));
           sum+=find(h[i],n);
        }
        printf("%d\n",sum);
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
