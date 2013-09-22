#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int t,l1,l2;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        l1=a.length();
        l2=b.length();
        if(l1<=l2)
        {
            int i=0;
            for(i=0;i<l2;i++)
            {
                if(b[i]!=a[i%l1])
                    break;
            }
            if(i!=l2) cout<<"NO\n";
            else
            {
                int k=l1-1;
                for(i=l2-1;i>=0;i--)
                {
                    if(k<0) k=l1-1;
                    if(b[i]!=a[k])
                        break;

                    k--;
                }
                if(i>=0) cout<<"NO\n";
                else    cout<<"YES\n";
            }
        }
        else
        {
            int i=0;
            for(i=0;i<l1;i++)
            {
                if(a[i]!=b[i%l2])
                    break;
            }
            if(i!=l1) cout<<"NO\n";
            else
            {
                int k=l2-1;
                for(i=l1-1;i>=0;i--)
                {
                    if(k<0) k=l2-1;
                    if(a[i]!=b[k])
                        break;

                    k--;
                }
                if(i>=0) cout<<"NO\n";
                else    cout<<"YES\n";
            }

        }
    }
    return 0;
}
