#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

vector<pair<int,int> > pts;

bool send(int id, int x, int y) {
    printf("%d %d %d\n", id, x, y);
    fflush(stdout);
    char temp[4];
    scanf("%s", temp);
    return temp[0]=='y';
}
int main()
{
    int n,x,y,m,c,r,id=-1,mincost;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        pts.push_back(make_pair(x,y));
    }
    sort(pts.begin(),pts.end());
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&r,&c);
        if(r==0)
        {
            if(id==-1)
            {
                id=i;
                mincost=c;
            }
            else if(c<mincost)
            {
                id=i;
                mincost=c;
            }
        }
    }
    for(int i=0;i<n;i+=2)
    {
        x=pts[i].first;
        for(int j=pts[i].second;j<=pts[i+1].second;j++)
        {
            if(send(id,x,j))
            {
                printf("-1 %d %d\n",x,j);
                return 0;
            }
        }
    }
    printf("-1 -1 -1\n");
    return 0;
}
