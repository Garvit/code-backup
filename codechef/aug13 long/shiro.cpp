#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std;

int a[100];
int cumulative[101];
double p[100];
double dp[100][10001];

int main()
{
    int t,n,sum,prev;
    double ans=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        ans=0;
        prev=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            cumulative[i]=prev+a[i];
            prev=cumulative[i];
        }
        for(int i=0;i<n;i++)
        {
            float pt;cin>>pt;
            p[i]=pt/100;
        }
        dp[0][0]=1-p[0];
        dp[0][a[0]]=p[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=cumulative[i-1];j++)
            {
                dp[i][j]=dp[i-1][j]*(1-p[i]);
            }
            for(int j=0;j<=cumulative[i-1];j++)
            {
                dp[i][j+a[i]]+=dp[i-1][j]*(p[i]);
            }

        }
        for(int i=(cumulative[n-1]+1)/2;i<=cumulative[n-1];i++)
        {
            ans+=dp[n-1][i];
        }
        cout<<ans<<endl;
        memset(cumulative,0,sizeof(cumulative));
        memset(dp,0,sizeof(dp));
    }
    return 0;
}
