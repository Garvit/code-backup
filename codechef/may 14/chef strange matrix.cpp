#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

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
vector<pair<int,int> > change;
int main()
{
    int n,m,p,x,y;
    n=scan();
    m=scan();
    p=scan();
    for(int i=0;i<p;i++)
    {
        x=scan();
        y=scan();
        change.push_back(make_pair(x,y));
    }
    sort(change.begin(),change.end());
    int k=0,prev=-1,curr=-1,pvalue,cvalue,cost;
    for(int i=1;i<=n;i++)
    {
        cost=m-1;
        prev=-1,curr=-1;
        for(;k<p;k++){
        if(change[k].first==i)
        {
            if(change[k].second!=curr)
            {
                if(curr==-1)
                {
                    curr=change[k].second;
                    cvalue=curr+1;
                }
                else
                {
                    if(prev!=-1)
                    {
                        if(pvalue>prev+1 && (curr!=prev+1 || (curr==prev+1 && cvalue<pvalue)))
                        {
                            printf("-1\n");
                            break;
                        }
                    }
                    prev=curr;
                    pvalue=cvalue;
                    curr=change[k].second;
                    cvalue=curr+1;
                }

            }
            else
            {
                cvalue++;
            }
            if(change[k].second==1)
            {
                cost--;
            }
            if(change[k].second==m)
            {
                cost++;
            }
        }
        else if(change[k].first>i)
        {
            if((prev!=-1 && pvalue>prev+1 && (curr!=prev+1 || (curr==prev+1 && cvalue<pvalue))) || (curr!=-1 && curr!=m && cvalue>curr+1))
                printf("-1\n");
            else printf("%d\n",cost);
            break;
        }}
        if(k>=p)
        {
            if((prev!=-1 && pvalue>prev+1 && (curr!=prev+1 || (curr==prev+1 && cvalue<pvalue))) || (curr!=-1 && curr!=m && cvalue>curr+1))
                printf("-1\n");
            else printf("%d\n",cost);
        }
    }
    return 0;
}
