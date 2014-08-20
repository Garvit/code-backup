#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
    string s,rem;
    cin>>s;
    int len=s.length(),l,r,ex,l2;
    l=s.find_first_of('|');
    r=len-l-1;
    int diff=abs(l-r);
    //cout<<s.substr(len-1);
    cin>>rem;
    ex=rem.length();
    l2=ex;
    ex-=diff;
    //cout<<ex<<endl;
    if(ex<0 || ex&1) cout<<"Impossible";
    else
    {
        if(l<r) cout<<rem.substr(l2-diff);
        cout<<rem.substr(0,ex/2);
        cout<<s<<rem.substr(ex/2,ex/2);
        if(r<l) cout<<rem.substr(l2-diff);
    }
    return 0;
}
