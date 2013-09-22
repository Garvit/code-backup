#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#define ll long long
using namespace std;

vector<ll> lit;
int arr[100];
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
    int t,n,m,c,p,v;
    ll ans=0;
    t=scan();
    while(t--)
    {
        ans=0;
        n=scan();
        m=scan();
        for(int i=0;i<m;i++)
        {
            p=scan();
            arr[p]++;
        }
        for(int i=0;i<n;i++)
        {
            c=scan();
            if(arr[i]==0)
            {
                for(int j=0;j<c;j++)
                    v=scan();
            }
            else if(arr[i]>=c)
            {
                for(int j=0;j<c;j++)
                {
                    v=scan();
                    ans+=v;
                }
            }
            else if(arr[i]<c)
            {
                lit.clear();
                for(int j=0;j<c;j++)
                {
                    v=scan();
                    lit.push_back(v);
                }
                sort(lit.begin(),lit.end(),greater<int>());
                for(int j=0;j<arr[i];j++)
                {
                    ans+=lit[j];
                }
            }
        }
        printf("%lld\n",ans);
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
