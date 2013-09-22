#include<iostream>
#include<cstring>
#define MOD 1009

using namespace std;
int pow(int base,int exp)
{
    int result=1;
    while(exp>0)
    {
        if(exp%2==1)
            result=(result*base)%MOD;
        exp=exp>>1;
        base=(base*base)%MOD;

    }
    return result;
}

int main()
{
    string s;
    cin>>s;
    int l=s.length();
    int ans=0,i;
    for(i=0;i<l;i++)
    {
        int t=s[i]-'a';
        if(i>1)
        {
            if(s[i-1]==s[i-2])
                break;
        }
        if(i!=0)
        {
            if(s[i-1]<s[i])
                t--;
        }
        ans=(ans+t*pow(25,l-1-i))%MOD;
        //cout<<ans<<endl;
    }
    if(i==l && l!=1)
    {
        if(s[i-1]!=s[i-2]) ans++;
    }
    cout<<ans;
    return 0;
}
