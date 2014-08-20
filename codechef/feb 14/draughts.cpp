#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

bool window[50001];
bool visited[50001];
vector<int> edges[50001];
int rans=0;

int dfs(int i)
{
    int v=0;
    if(window[i]==true) v=1;
    visited[i]=true;
    for(int j=0;j<edges[i].size();j++)
    {
        if(visited[edges[i][j]]==false)
        {
            v+=dfs(edges[i][j]);
        }
    }
    if(v>0) rans++;
    //printf("%d %d\n",i,rans);
    return v;
}
int main()
{
    int n,m,i,b,x,y,g1,g2;
    long long fans=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&b);
        window[i]=b;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for(i=1;i<=n;i++)
    {
        if(window[i]==true && visited[i]==false)
        {
            long long t=dfs(i);
            fans+=t*(t-1)/2;
            if(t==1) rans--;
        }
    }
    printf("%lld %d\n",fans,rans);
    return 0;
}

