#include<stdio.h>
#include<limits.h>
#define min(a,b) (a<b?a:b)
int arr[1001];
int dp[1001];
int main()
{
    int n,k,i,j,sum=0,ans;
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=1;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
        dp[i]=INT_MAX;
    }
    for(i=n;i>0;i--)
    {
        for(j=1;j<=k;j++)
        {
            if(i-j < 0) break;
            dp[i-j]=min(dp[i-j],arr[i-j]+dp[i]);
        }
    }
    //for(i=0;i<=n;i++)
    //    printf("%d\n",dp[i]);
    ans=dp[1];
    for(i=2;i<=k;i++)
    {
        ans=min(ans,dp[i]);
    }
    printf("%d",sum-ans);
    return 0;
}
