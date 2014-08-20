#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <bitset>
#define MOD 1000000007
using namespace std;

int count_ways[1024][101];
vector<int> value[10];
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d\n",&n);
        string line;
        int num,ans=0,new_mask,max_shirt=0;
        for(int i=0;i<n;i++)
        {
            int k=0;
            getline(cin,line);
            size_t pos=0,newpos;
            while((newpos=line.find(' ',pos)) != string::npos)
            {
                num=atoi(line.substr(pos,newpos-pos).c_str());
                value[i].push_back(num);
                if(num>max_shirt) max_shirt=num;
                count_ways[1<<i][num]=1;
                pos=newpos+1;
            }
            num=atoi(line.substr(pos).c_str());
            value[i].push_back(num);
            if(num>max_shirt) max_shirt=num;
            sort(value[i].begin(),value[i].end(),greater<int>());
            count_ways[1<<i][num]=1;
        }
        for(int mask = 1; mask < (1<<n)-1; ++mask)
        {
            for(int shirt=1;shirt<=max_shirt;++shirt)
            {
                if(count_ways[mask][shirt]==0) continue;
                for(int i=0;i<n;++i)
                {
                    if(mask & (1<<i)) continue;
                    for(int j=0;j<value[i].size();++j)
                    {
                        if(value[i][j]<=shirt) break;
                        new_mask=mask | (1<<i);
                        count_ways[new_mask][value[i][j]] += count_ways[mask][shirt];
                        if(count_ways[new_mask][value[i][j]]>=MOD)
                            count_ways[new_mask][value[i][j]] -=MOD;
                        //cout << new_mask << " " << value[i][j] << " "<<count_ways[new_mask][value[i][j]]<<endl;
                    }

                }
            }
        }
        int all=(1<<n)-1;
        for(int shirt=1;shirt<=max_shirt;++shirt)
        {
            ans += count_ways[all][shirt];
            if(ans>=MOD) ans-=MOD;
        }
        printf("%d\n",ans);
        for(int i=0;i<10;++i)
        {
            value[i].clear();
        }
        memset(count_ways,0,sizeof(count_ways));
    }
    return 0;
}
