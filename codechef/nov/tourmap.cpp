#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#include<string>
#include<utility>
using namespace std;
map< string, pair <string,int> > m;
map< string, string > m1;

int main()
{
    int t,i,n,totalcost=0,j,c;
    map< string, pair< string,int > >::iterator it1;

    string first,a,b,doll;
    cin>>t;

    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            printf("0$\n");
            continue;
        }
        totalcost=0;
        for(i=0;i<(n-1);i++)
        {
            cin>>a>>b>>c;
            cin>>doll;
            pair<string,int> temp (b,c);
            //cout<<a<<b<<c<<endl;
            totalcost+=c;
            m.insert(pair< string ,pair< string,int > >(a,temp) );
            m1.insert(pair< string,string >(b,a));


        }

        for(it1=m.begin();it1!=m.end();it1++)
        {
            if(m1.find((*it1).first)==m1.end())
                break;
        }

        cout<<(*it1).first<<" "<<(*it1).second.first<<" "<<(*it1).second.second<<"$"<<endl;
        first=(*it1).second.first;
        for(i=0;i<n-2;i++)
        {
            cout<<first<<" "<<m[first].first<<" "<<m[first].second<<"$"<<endl;
            first=m[first].first;
        }
        cout<<totalcost<<"$"<<endl;
        m.clear();
        m1.clear();
    }
    return 0;
}

