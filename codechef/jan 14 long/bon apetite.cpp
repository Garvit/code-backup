#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<vector>
using namespace std;
vector<pair<int,int> > dp;
int start[100002];
int end[100002];
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
int main()
{
    int t,n,k,p,ans=0;
    t=scan();
    while(t--)
    {
        ans=0;
        map<int,set<int> > prefer;
        map<int,set<int> >::iterator it;
        n=scan();
        k=scan();
        for(int i=0;i<n;i++)
        {
            start[i]=scan();
            end[i]=scan();
            p=scan();
            it=prefer.find(p);
            if(it==prefer.end())
            {
                set<int> s;
                s.insert(i);
                prefer.insert(make_pair(p,s));
            }
            else
            {
                (it->second).insert(i);
            }
        }
        for(it=prefer.begin();it!=prefer.end();it++)
        {
            set<int> s=it->second;
            int count=1;
            for(set<int>::iterator its=s.begin();its!=s.end();its++)
            {
                dp.push_back(make_pair(end[*its],*its));
            }
            sort(dp.begin(),dp.end());
            int ed=dp[0].first;
            for(int i=1;i<dp.size();i++)
            {
                if(start[dp[i].second]>=ed)
                {
                    count++;
                    ed=dp[i].first;
                }
            }
            ans+=count;
            dp.clear();
        }
        printf("%d\n",ans);
    }
    return 0;
}
