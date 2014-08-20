#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;


int main() {
    int n,k;
    cin>>n;
    int *arr=new int[n];
    cin>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll *sum=new ll[n-k+2];
    sum[0]=0;
    for(int i=0;i<k-1;i++)
    {
        sum[0]+=arr[i];
    }
    for(int i=1;i<=n-k+1;i++)
    {
        sum[i]=sum[i-1]-arr[i-1]+arr[i+k-2];
    }
    ll ans,val=0,m=1-k;
    for(int i=0;i<k;i++)
    {
        val+=m*arr[i];
        m+=2;
    }
    ans=val;
    for(int i=1;i<=n-k;i++)
    {
        val=val-(long long)arr[i-1]*(1-k)+(long long)arr[i+k-1]*(k-1)-2*sum[i];
        if(val<ans)
            ans=val;
    }
    cout<<ans;
    return 0;
}

