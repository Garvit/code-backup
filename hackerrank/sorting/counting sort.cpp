#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cnt[100];
int main() {

    int n,i;
    scanf("%d",&n);
    int *a=new int[n];
    string *s=new string[n];
    string *ans=new string[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>s[i];
        cnt[a[i]]++;
    }
    int t=cnt[0],t1;
    cnt[0]=0;
    for(i=1;i<100;i++)
    {
        t1=cnt[i];
        cnt[i]=cnt[i-1]+t;
        t=t1;
        //cout<<cnt[i]<<" ";
    }

    for(i=0;i<n;i++)
    {
        int start=cnt[a[i]];
        cnt[a[i]]++;
        if(i<n/2)
            ans[start]="-";
        else ans[start]=s[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
