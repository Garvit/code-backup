#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;


long long bit1[100001];
long long bit2[100001];
int n;
void update1(int i,long long val)
{
    while(i<=n)
    {
        bit1[i]+=val;
        i+=(i&-i);
    }
}
long long query1(int i)
{
    long long ans=0;
    while(i>0)
    {
        ans+=bit1[i];
        i-=(i&-i);
    }
    return ans;
}
void update2(int i,long long val)
{
    while(i<=n)
    {
        bit2[i]+=val;
        i+=(i&-i);
    }
}
long long query2(int i)
{
    long long ans=0;
    while(i>0)
    {
        ans+=bit2[i];
        i-=(i&-i);
    }
    return ans;
}
vector<pair<int,int> > v;
void solve()
{
    int num;
    scanf("%d",&n);
    for(int i=0;i<n;++i){ scanf("%d",&num); v.push_back(make_pair(-num,i+1));}
    sort(v.begin(),v.end());
    //update1(v[0].second,1);
    long long ans=0,last=0;
    //ret=query1(arr[1]);
    //update2(arr[1]+1,ret);
    //update1(arr[1]+1,1);
    int l=0,r=0;
    for(int i=1;i<n;++i)
    {
        if(v[i].first!=v[i-1].first){
            for(int j=l;j<=r;++j){
                update2(v[j].second,query1(v[j].second));
            }
            //last=query1(v[l].second);
            for(int j=l;j<=r;++j){
               // printf("updating %d %lld\n",v[j].second,last);
                //update2(v[j].second,last);
                update1(v[j].second,1);
            }
            l=i;
        }
        r=i;
        ans+=query2(v[i].second);
        //last=query1(v[i].second);
        //update2(v[i],);
        //update1(v[i],1);
        //printf("ans : %lld\n",ans);
    }
    //for(int i=1;i<=n;++i) printf("%lld %lld\n",query1(i),query2(i));
    printf("%lld\n",ans);
}
int main() {
	int t=1;
	//scanf("%d",&t);
	while(t--){
	    solve();
	}
	return 0;
}

