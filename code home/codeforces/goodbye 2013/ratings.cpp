#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<utility>

using namespace std;
pair<int,int> rate[300002];
int ans[300002];
int main()
{
    int n,i,r,last=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>r;
        rate[i]=make_pair(r,i);
    }
    sort(rate,rate+n);
    for(i=0;i<n;i++)
    {
        if(rate[i].first<=last)
        {
            last++;
        }
        else
        {
            last=rate[i].first;
        }
        ans[rate[i].second]=last;
    }
    for(i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
