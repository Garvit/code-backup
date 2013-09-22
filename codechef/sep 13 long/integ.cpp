#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#define ll long long
using namespace std;

vector<ll> numbers;
ll inline scan()
{
    ll N = 0,sign=1;
    char C;
    C=getchar();
    while ((C < '0' || C>'9') && C!='-') C=getchar();
    if(C=='-'){ sign=-1;C=getchar(); }
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar();
    }

    return N*sign;
}
int main()
{
    ll n,x,ans=0,p;
    n=scan();
    for(int i=0;i<n;i++)
    {
        p=scan();
        //cout<<p<<endl;
        if(p<0)
            numbers.push_back(-p);
    }
    sort(numbers.begin(),numbers.end());
    x=scan();
    int l=numbers.size();
    if(l<=x)
    {
        for(int i=0;i<l;i++)
        {
            ans+=numbers[i];
        }
    }
    else
    {
        for(int i=l-x;i<l;i++)
        {
            ans+=numbers[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
