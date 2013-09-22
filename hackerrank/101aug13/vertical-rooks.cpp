#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<math.h>
using namespace std;

int a[2010];
int b[2010];

int main() {
    int t,n,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans^(abs(a[i]-b[i])-1);
        }
        if(ans==0) cout<<"player-1"<<endl;
        else cout<<"player-2"<<endl;

    }
    return 0;
}

