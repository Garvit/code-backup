#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <utility>

#define MAXN 110
#define LL long long
using namespace std;

const LL INF=20000000000000LL;
vector<pair<LL,LL> > arr[MAXN];
LL inp[MAXN];
LL graph[MAXN][MAXN],lx[MAXN],ly[MAXN];
LL slack[MAXN],yx[MAXN],visx[MAXN],visy[MAXN],flag=0;
int n;

bool check(int p)
{
	visx[p]=flag;
	for(int i=0;i<n;++i)
	{
		if(lx[p]+ly[i]==graph[p][i] && visy[i]!=flag)
		{
			visy[i]=flag;
			if(yx[i]==-1 || check(yx[i]))
			{
				yx[i]=p;
				return true;
			}
		}
		slack[i]=min(slack[i],graph[p][i]-lx[p]-ly[i]);
	}
	return false;
}
LL hungarian()
{
	for(int i=0;i<n;++i)
		lx[i]=INF, ly[i]=0, yx[i]=-1;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j) lx[i]=min(lx[i],graph[i][j]);
	}

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j) slack[j]=INF;

		for(flag++;!check(i);++flag)
		{
			LL delta=INF;
			for(int j=0;j<n;++j)
				if(visy[j]!=flag)
					delta=min(delta,slack[j]);
			for(int j=0;j<=i;++j)
				if(visx[j]==flag) lx[j]+=delta;
			for(int j=0;j<n;++j)
				if(visy[j]==flag) ly[j]-=delta;
			for(int j=0;j<n;++j) slack[j]=INF;

			if(lx[i]>=INF) return INF+1;
		}
	}
	LL ans=0;
	for(int i=0;i<n;++i) ans+=lx[i]+ly[i];
	return ans;
}
int main()
{
    int q,m;
    LL u,c;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
    	scanf("%d",&m);
    	for(int j=0;j<m;++j)
    	{
    		scanf("%lld %lld",&u,&c);
    		arr[i].push_back(make_pair(u,c));
    	}
    }
    scanf("%d",&q);
    while(q--)
    {
    	for(int i=0;i<n;++i)
    	{
    		scanf("%lld",&inp[i]);
    	}
    	for(int i=0;i<n;++i)
    		for(int j=0;j<n;++j) graph[i][j]=INF;
    	for(int i=0;i<n;++i)
    	{
    		for(int j=0;j<arr[i].size();++j)
    		{
    			for(int k=0;k<n;++k)
    			{
    				if(arr[i][j].first==inp[k]) graph[i][k]=arr[i][j].second;
    			}
    		}
    	}

    	LL ans=hungarian();
    	if(ans>=INF) printf("-1\n");
    	else printf("%lld\n",ans);
    }
    return 0;
}
