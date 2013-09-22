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
int city[2000][2000];
int x1[1000];
int y1[1000];
int x2[1000];
int y2[1000];
int dp[1000][1001];
int eval(int i,int k,int q)
{
    if(i>=q) return 0;
    if(k<=0) return 0;
    if(dp[i][k]) return dp[i][k];
    int j,z,sum=0,val1=0,val2;
    for(j=x1[i];j<=x2[i];j++)
    {
        for(z=y1[i];z<=y2[i];z++)
        {
            sum+=city[j-1][z-1];
        }
    }
    if(sum<=k)
    {
        val1=(x2[i]-x1[i]+1)*(y2[i]-y1[i]+1)+eval(i+1,k-sum,q);
    }
    val2=eval(i+1,k,q);
    if(val2>=val1)
    {
        dp[i][k]=val2;
        return val2;
    }
    else
    {
        dp[i][k]=val1;
        return val1;
    }

}
int main()
{
    int n,m,q,k,i,j;
    n=scan();
    m=scan();
    q=scan();
    k=scan();
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            city[i][j]=scan();
        }
    }
    for(i=0;i<q;i++)
    {
        x1[i]=scan();
        y1[i]=scan();
        x2[i]=scan();
        y2[i]=scan();
    }
    int ans=eval(0,k,q);
    printf("%d",ans);
    return 0;
}
