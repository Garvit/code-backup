#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string.h>
#include<utility>
#include<map>
#define LL long long
#define getchar getchar_unlocked
using namespace std;
LL inline scan()
{
    LL N = 0;
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
bool compare(pair<LL,LL> a,pair<LL,LL> b)
{
    return a.second < b.second;

}
map<LL,LL> distinct;

int main()
{
    LL t,n,b,l,count;
    map<LL,LL>::iterator it;
    long long ans=0,total=0;
    t=scan();
    while(t--)
    {
        ans=0;total=0;
        n=scan();
        for(LL i=0;i<n;i++)
        {
            b=scan();
            l=scan();
            it=distinct.find(b);
            if(it!=distinct.end())
            {
                if(l<(it->second)){
                    total+=it->second ;it->second=l; }
                else
                    total+=l;
            }
            else
            {
                distinct.insert(it,pair<LL,LL>(b,l));
            }
        }
        vector<pair<LL,LL> > v;
        copy(distinct.begin(),distinct.end(),back_inserter(v));
        sort(v.begin(),v.end(),compare);

        count=1;
        for(vector<pair<LL,LL> >::iterator it=v.begin();it!=v.end();it++)
        {
            ans+=(it->second)*count;
            count++;
        }
        count--;
        ans+=total*count;
        printf("%lld\n",ans);
        distinct.clear();
    }
    return 0;
}

