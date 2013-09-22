#include<iostream>
#include<vector>
#include<set>
using namespace std;

int arr[100001];
int total[100001];
int grp(int n)
{
    while(arr[n]!=n)
    {
        n=arr[n];
    }
    arr[n]=n;
    return n;
}
int main()
{
    int n,num,a,b;
    cin>>n>>num;
    for(int i=0;i<n;i++)
    {
        arr[i]=i;
    }
    for(int i=0;i<num;i++)
    {
        cin>>a>>b;
        int g1=grp(a),g2=grp(b);
        //cout<<g1<<" "<<g2;
        arr[g2]=g1;

    }
    long long ans=0,tot=n;
    for(int i=0;i<n;i++)
    {
        arr[i]=grp(i);
        total[arr[i]]++;
        //cout<<arr[i]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        tot-=total[i];
        ans+=(total[i]*tot);
    }
    cout<<ans;

    return 0;
}
