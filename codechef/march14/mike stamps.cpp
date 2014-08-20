#include<iostream>
#include<stdio.h>
#include<bitset>
#include<algorithm>
using namespace std;

bitset<20001> arr[20];
bitset<20> edges[20];
int n,m;
int func(int i,bitset<20> s,int c)
{
    if(i==m) return c;
    bitset<20> t=s&edges[i];
    if(t.any())
    {
        return func(i+1,s,c);
    }
    else
    {
        t=s;
        t[i]=1;
        return max(func(i+1,t,c+1),func(i+1,s,c));
    }
}
int main()
{
    int k,a;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&a);
            arr[i][a]=1;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            bitset<20001> b=arr[i]&arr[j];
            if(b.any())
            {
                edges[i][j]=edges[j][i]=1;
            }
        }
    }
    //cout<<edges[0]<<endl;
    bitset<20> b;
    int ans=func(0,b,0);
    cout<<ans;
    return 0;
}
