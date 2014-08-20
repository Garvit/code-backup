#include <iostream>
#include <queue>
#include <stdio.h>
#include <set>
#define getchar getchar_unlocked
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
set<int> tables;
vector<int> customers(400);
vector<queue<int> > arrival_time(401);
int main()
{
    int t,n,m,c;
    t=scan();
    while(t--)
    {
        n=scan();
        m=scan();
        int ans=0,remove_cust,remove_time;
        tables.clear();
        for(int i=0;i<m;++i)
        {
            customers[i]=scan();
            arrival_time[customers[i]].push(i);
        }
        for(int i=0;i<m;++i)
        {
            if(tables.find(customers[i])==tables.end())
            {
                ++ans;
                if(tables.size()==n)
                {
                    remove_time=-1;
                    for(set<int>::iterator it=tables.begin();it!=tables.end();++it)
                    {
                        if (arrival_time[*it].empty())
                        {
                            remove_cust=*it;
                            break;
                        }
                        if(arrival_time[*it].front()>remove_time)
                        {
                            remove_cust=*it;
                            remove_time=arrival_time[*it].front();
                        }
                    }
                    tables.erase(remove_cust);
                }
                tables.insert(customers[i]);
            }
            arrival_time[customers[i]].pop();
        }
        printf("%d\n",ans);
    }
    return 0;
}
