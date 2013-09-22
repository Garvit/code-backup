#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int x[100001],y[100001];
float max(float a,float b)
{
    return a>b?a:b;
}
int main()
{
    int n,q,l,r;
    float ansx=0.0,ansy=0.0,s;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>y[i];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>l>>r;
        ansx=0.0;ansy=0.0;s=0.0;
        for(int j=l;j<=r;j++)
        {
            ansx+=x[j];
            ansy+=y[j];
        }
        //cout<<ansx<<" "<<ansy<<endl;
        ansx/=(r-l+1);
        ansy/=(r-l+1);
        //cout<<ansx<<" "<<ansy<<endl;
        for(int j=l;j<=r;j++)
        {
            s+=max(fabs(x[j]-ansx),fabs(y[j]-ansy));
        }
        cout<<s<<endl;
    }
    return 0;
}
