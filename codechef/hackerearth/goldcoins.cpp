#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<map>
#include<utility>
using namespace std;
map< int,long long > m;

long long coin(long long n)
{
    if(n<12)
        return n;
    if(m.find(n)!=m.end())
    {
        return m[n];
    }
    long long a;
    a=coin(n/2)+coin(n/3)+coin(n/4);
    m[n]=a>n?a:n;
    return m[n];
}
int main()
{
    int t;
    long long n,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu",&n);
        //cin>>n;
        ans=coin(n);
        printf("%llu\n",ans);
        m.clear();
    }
    return 0;
}
