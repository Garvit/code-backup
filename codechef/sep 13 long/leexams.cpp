#include<iostream>
#include<set>
#include<utility>
#define ld long double
using namespace std;
int num[51][2];
ld prob[51];
ld func(pair<set<int>,ld> p,int i,int n)
{
    if(i==n) return p.second;

    set<int> s=p.first;
    ld val1,val2;
    if(s.find(num[i][0])!=s.end())
        val1=0;
    else{
        s.insert(num[i][0]);
        val1=func(pair<set<int>,ld>(s,(p.second)*prob[i]),i+1,n);
        s.erase(num[i][0]);
    }

    if(s.find(num[i][1])!=s.end())
        val2=0;
    else{
        s.insert(num[i][1]);
        val2=func(pair<set<int>,ld>(s,p.second*(1-prob[i])),i+1,n);
        s.erase(num[i][1]);
    }
    return val1+val2;

}
int main()
{
    int t,n;
    ld ans=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i=0;i<n;i++)
        {
            ld p;
            cin>>p>>num[i][0]>>num[i][1];
            prob[i]=p/100;
        }
        set<int> chosen;
        ans=func(pair<set<int>,ld>(chosen,1),0,n);
        cout<<ans<<endl;
    }
    return 0;
}
