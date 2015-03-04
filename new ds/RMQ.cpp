#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define N 100010
using namespace std;

LL power(LL base,LL exp)
{
    LL result=1;
    while(exp>0)
    {
        if(exp&1) result=(result*base)%MOD;
        base=(base*base)%MOD;
        exp>>=1;
    }
    return result;
}
int log_2(int x)
{
    int ans=0;
    while(x>>=1) ans++;
    return ans;
}
int arr[N];
int dpmin[N][20],dpmax[N][20];
int n,k;
void process()
{
    for(int i=0;i<n;++i)
    {
        dpmin[i][0]=arr[i];
        dpmax[i][0]=arr[i];
    }
    for(int j=1;(1<<j)<=n;++j)
    {
        for(int i=0;i+(1<<j)-1<n;++i)
        {
            dpmin[i][j]=min(dpmin[i][j-1],dpmin[i+(1<<(j-1))][j-1]);
            dpmax[i][j]=max(dpmax[i][j-1],dpmax[i+(1<<(j-1))][j-1]);
        }
    }
}
int rmin(int i,int j)
{
    int l=log_2(j-i+1);
    int ans=min(dpmin[i][l],dpmin[j-(1<<l)+1][l]);
}
int rmax(int i,int j)
{
    int l=log_2(j-i+1);
    int ans=max(dpmax[i][l],dpmax[j-(1<<l)+1][l]);
}
void solve()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&arr[i]);
    }
    memset(dp,0,sizeof(dp));
    process();
    int ma=rmax(0,n-1),mi=rmin(0,n-1);
    if(ma-mi<k){
        printf("0\n");
        return;
    }
    int l=1,r=n,ans=n,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        for(int i=0;i<=mid;++i)
        {
            ma=rmax(0+i,n-1-(mid-i));
            mi=rmin(0+i,n-1-(mid-i));
            if(ma-mi == k){
                ans=min(ans,mid);
                l=mid+1;
                break;
            }
            if(ma-mi>k){

            }
        }
    }
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    solve();
	}
	return 0;
}

