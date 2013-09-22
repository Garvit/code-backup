#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<set>
using namespace std;
int arr[30][30];
int grp[30];
vector<pair<pair<int,int>,int> > edges;
set<pair<pair<int,int>,int> > mst;

bool compare(pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2)
{
    return p1.second<p2.second;
}
int findgrp(int a)
{
    int n=a;
    while(grp[a]!=a)
    {
        a=grp[a];
    }
    grp[n]=a;
    return a;
}
void makeset(int n)
{
    for(int i=0;i<n;i++)
    {
        grp[i]=i;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int p;
            cin>>p;
            arr[i][j]=p;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                edges.push_back(pair<pair<int,int>,int>(pair<int,int>(i,j), arr[i][j]));
            }
        }
    }
    makeset(n);
    sort(edges.begin(),edges.end(),compare);
    for(int i=0;i<edges.size();i++)
    {
        int g1=findgrp(edges[i].first.first);
        int g2=findgrp(edges[i].first.second);
        if(g1!=g2)
        {
            mst.insert(edges[i]);
            grp[g2]=g1;
        }
        //cout<<edges[i].first.first<<" "<<edges[i].first.second<<" "<<edges[i].second<<endl;
    }
    for(set<pair<pair<int,int>,int> >::iterator it=mst.begin();it!=mst.end();it++)
    {
        cout<<(*it).first.first<<" "<<(*it).first.second<<" "<<(*it).second<<endl;
    }
    return 0;
}
