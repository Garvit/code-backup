#include<stdio.h>
#include<stdbool.h>

long long dp[100000];
int arr[100000];
bool found[100000];
int main()
{
    int n,i=0,j;
    long long ans=0;
    while(scanf("%d",&n)!=EOF)
    {
        arr[i]=n;
        dp[i]=1;
        for(j=0;j<i;j++)
        {
            if(arr[j]<arr[i] && found[j]==false)
            {
                dp[i]+=dp[j];
            }
            if(arr[j]==arr[i])
            {
                dp[j]=0;
                found[j]=true;
            }
        }
        i++;
    }
    for(j=0;j<i;j++)
    {
        ans+=dp[j]==0?0:(dp[j]-1);
    }
    printf("%lld\n",ans);
    return 0;
}
