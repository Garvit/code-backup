#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<set>
#include<climits>
using namespace std;
int con[30][30];
int man[30][30];
int grp[30];
vector<pair<pair<int,int>,pair<int,int> > > edges;

int ans=0;
bool compare(pair<pair<int,int>,pair<int,int> > p1, pair<pair<int,int>,pair<int,int> > p2)
{
    return (p1.second.first+p1.second.second)<(p2.second.first+p2.second.second);
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
            con[i][j]=p;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int p;
            cin>>p;
            man[i][j]=p;
        }
    }
    makeset(n);
    for(int z=1;z<n;z++){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                //cout<<i<<" "<<j<<" "<<arr[i][j]<<endl;
                edges.push_back(pair<pair<int,int>,pair<int,int> >(pair<int,int>(i,j), pair<int,int>(min(con[i][j],con[j][i]),min(man[i][j],man[j][i]))));
            }
        }
    }
    sort(edges.begin(),edges.end(),compare);
    /*for(int i=0;i<edges.size();i++)
    {
        cout<<edges[i].first.first<<" "<<edges[i].first.second<<edges[i].second<<endl;

    }*/
    for(int i=0;i<edges.size();i++)
    {
        int g1=findgrp(edges[i].first.first);
        int g2=findgrp(edges[i].first.second);
        if(g1!=g2)
        {
            cout<<edges[i].first.first<<" "<<edges[i].first.second<<endl;
            int mc=edges[i].second.second;
            int cc=edges[i].second.first;
            if(mc==man[edges[i].first.first][edges[i].first.second])
            {
                for(int j=0;j<n;j++)
                    man[edges[i].first.first][j]=1000000;
            }
            else
            {
                for(int j=0;j<n;j++)
                    man[edges[i].first.second][j]=1000000;
            }
            if(cc==con[edges[i].first.first][edges[i].first.second])
            {
                for(int j=0;j<n;j++)
                    con[edges[i].first.first][j]=1000000;
            }
            else
            {
                for(int j=0;j<n;j++)
                    con[edges[i].first.second][j]=1000000;
            }
            ans+=mc+cc;
            grp[g2]=g1;
            break;
        }

    }
    edges.clear();
    }
    cout<<ans<<endl;

    return 0;
}

