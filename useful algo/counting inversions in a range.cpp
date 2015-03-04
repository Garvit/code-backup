#include <bits/stdc++.h>
#define N 100001
#define piii pair<pair<int,int>,int>
using namespace std;

const int sz=320;
vector<pair<int,int> > arrvec;
int arr[N];
vector<piii> queries;
int bit1[N],bit2[N],use[N];
long long qans[N];
int qi;
bool cmp(piii a,piii b)
{
	if(a.first.first/sz == b.first.first/sz) return a.first.second<b.first.second;
	return a.first.first/sz < b.first.first/sz;
}
void update1(int i,int val)
{
	while(i<N)
	{
		bit1[i]+=val;
		i+=(i&-i);
	}
}
int query1(int i)
{
	int res=0;
	while(i)
	{
		res+=bit1[i];
		i-=(i&-i);
	}
	return res;
}
void update2(int i,int val)
{
	while(i<N)
	{
		if(use[i]!=qi)
		{
			bit2[i]=0;
		}
		use[i]=qi;
		bit2[i]+=val;
		i+=(i&-i);
	}
}
int query2(int i)
{
	int res=0;
	while(i)
	{
		if(use[i]!=qi)
			bit2[i]=0;
		use[i]=qi;
		res+=bit2[i];
		i-=(i&-i);
	}
	return res;
}
int main()
{
    int n,q,num,l,r;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;++i)
    {
    	scanf("%d",&num);
    	arrvec.push_back(make_pair(num,i));
    }
    sort(arrvec.begin(),arrvec.end());
    arr[arrvec[0].second]=1;
    int store=1;
    for(int i=1;i<n;++i)
    {
    	if(arrvec[i].first!=arrvec[i-1].first) store++;
    	arr[arrvec[i].second]=store;
    }
    for(int i=0;i<q;++i)
    {
    	scanf("%d %d",&l,&r);
    	queries.push_back(make_pair(make_pair(l-1,r-1),i));
    }
    sort(queries.begin(),queries.end(),cmp);
    int start=0,end=0,cnt=0;
    long long res=0;
    for(int i=0;i<q;++i)
    {
    	l=queries[i].first.first;
    	r=queries[i].first.second;
    	if(l>=start)
    	{
    		start=(l/sz+1)*sz;
    		end=start;
    		cnt=0;
    		res=0;
    		memset(bit1,0,sizeof(bit1));
    	}
    	while(end<=r)
    	{
    		res+=cnt-query1(arr[end]);
    		update1(arr[end],1);
    		end++;
    		cnt++;
    	}
    	long long ans=res;
    	qi++;
    	for(int j=min(start-1,r);j>=l;--j)
    	{
    		ans+=query1(arr[j]-1)+query2(arr[j]-1);
    		update2(arr[j],1);
    	}
    	qans[queries[i].second]=ans;
    }
    for(int i=0;i<q;++i) printf("%lld\n",qans[i]);
    return 0;
}

