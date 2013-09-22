#include<iostream>

using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    if(m==1) cout<<n;
    else if(n==1) cout<<m;
    else if(m%2==0) cout<<2*m;
    else if(n%2==0) cout<<2*(m+n-2);
    else cout<<m*n;
    return 0;
}
