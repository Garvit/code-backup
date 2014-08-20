#include<string>
#include<iostream>

using namespace std;

int main()
{
    string s;
    long long ans=1;
    cin>>s;
    int len=s.length(),l=1;
    for(int i=0;i<s.length()-1;++i)
    {
        if((s[i]-48)+(s[i+1]-48)==9)
            l++;
        else
        {
            if(l>1 && l%2==1)
                ans=ans*((l+1)/2);
            l=1;
        }
    }
    if(l>1 && l%2==1)
        ans=ans*(l+1)/2;
    cout<<ans;
    return 0;
}
