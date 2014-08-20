// Dijkstras
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <set>
#include <vector>
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

int main()
{
    int n,m,a,b;
    n=scan();
    m=scan();
    set<int>* out = new set<int>[n];
    set<int>* in = new set<int>[n];
    set<int>* cost_vertices = new set<int>[n];
    vector<int> cost(n,-1);
    cost[0]=0;
    cost_vertices[0].insert(0);
    while(m--)
    {
        a=scan();
        b=scan();
        if (a!=b)
        {
            out[a-1].insert(b-1);
            in[b-1].insert(a-1);
        }
    }
    int min_cost = 0,curr;
    bool flag=true;
    while(1)
    {
        while(min_cost < 100000 && cost_vertices[min_cost].empty())
        {
            ++min_cost;
        }
        if (min_cost>=100000) break;
        curr=*cost_vertices[min_cost].begin();
        cost_vertices[min_cost].erase(curr);
        if (curr == n-1)
        {
            printf("%d",cost[curr]);
            flag=false;
            break;
        }
        for (set<int>::iterator it = out[curr].begin(); it!=out[curr].end(); ++it)
        {
            if (cost[*it]==-1 || cost[curr]<cost[*it]) {
                if (cost[*it]!=-1) cost_vertices[cost[*it]].erase(*it);
                cost[*it] = cost[curr];
                cost_vertices[cost[curr]].insert(*it);
            }
        }
        for (set<int>::iterator it = in[curr].begin(); it!=in[curr].end(); ++it)
        {
            if (cost[*it]==-1 || cost[curr] + 1 < cost[*it]) {
                if (cost[*it]!=-1) cost_vertices[cost[*it]].erase(*it);
                cost[*it] = cost[curr] + 1;
                cost_vertices[cost[curr] + 1].insert(*it);
            }
        }
    }
    if(flag)
    {
        printf("-1");
    }
    return 0;
}
