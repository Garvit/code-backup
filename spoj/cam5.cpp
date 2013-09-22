#include<stdio.h>
#include<iostream>
#include<vector>
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
char colour[100000];
vector<int> arr[100000];

void dfs(int s)
{
    if(arr[s].empty()) return;
    vector<int>::iterator it;
    for(it=arr[s].begin();it!=arr[s].end();it++)
    {
        if(colour[*it]=='\0')
        {
            colour[*it]='B';
            dfs(*it);
        }
    }
}
int main()
{
    int t,n,e,i,a,b,count;
    t=scan();
    while(t--)
    {
        n=scan();
        e=scan();
        count=0;
        for(i=0;i<e;i++)
        {
            a=scan();
            b=scan();
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        for(i=0;i<n;i++)
        {
            if(colour[i]=='\0')
            {
                count++;
                dfs(i);
            }
        }
        printf("%d\n",count);
        for(i=0;i<n;i++)
        {
            colour[i]='\0';
            arr[i].clear();
        }
    }
    return 0;
}
