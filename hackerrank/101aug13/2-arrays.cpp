#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
vector<ll> a;
vector<ll> b;
int main()
{
    int t,n,k;
    ll num;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            a.push_back(num);
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++)
        {
            cin>>num;
            b.push_back(num);
        }
        sort(b.begin(),b.end(),greater<ll>());
        int i;
        for(i=0;i<n;i++)
        {
            if(a[i]+b[i] < k)
                break;
        }
        if(i==n) cout<<"YES\n";
        else cout<<"NO\n";

        a.clear();
        b.clear();
    }
}
