#include<stdio.h>

int arr[20][2];
int dp[20][101];

int eval(int i,int m,int n)
{
    if(i>=m) return 0;
    if(dp[i][n]) return dp[i][n];

    if(i==m-1)
    {
        if(n>=arr[i][0] && n<=arr[i][1])
            return 1;
    }
    int ans=0,k;
    for(k=arr[i][0];k<=arr[i][1] && k<=n;k++)
    {
        ans+=eval(i+1,m,n-k);
    }
    dp[i][n]=ans;
    return ans;
}

int main()
{
    int n,m,i;
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(n==0 && m==0) break;

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&arr[i][0],&arr[i][1]);
        }

        int ans=eval(0,m,n);
        printf("%d\n",ans);
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
