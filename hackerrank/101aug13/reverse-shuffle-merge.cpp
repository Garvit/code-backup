#include<iostream>

using namespace std;

int req[26];
int data[10007][26];
int len;
string s;
bool check(int a[26],int b[26])
{
    for(int i=0;i<26;i++)
    {
        if(a[i]>b[i]) return false;
    }
    return true;
}
void func(string str,int p)
{
    //cout<<str<<endl;
    if(str.length()==len)
    {
        cout<<str<<endl;
        return;
    }
    for(int i=0;i<26;i++)
    {
        if(req[i]!=0)
        {
            char c=i+'a';
            int k=s.find_last_of(c,p);
            //cout<<c<<" "<<k<<endl;
            if(check(req,data[k]))
            {
                req[i]--;
                func(str+c,k-1);
                break;
            }

        }
    }
}
int main()
{
    cin>>s;
    int l=s.length();
    len=l/2;
    for(int i=0;i<l;i++)
    {
        int p=s[i]-'a';
        req[p]++;
        if(i!=0){
        for(int j=0;j<26;j++)
        {
            data[i][j]=data[i-1][j];
        }
        }
        data[i][p]++;
    }
    for(int i=0;i<26;i++)
    {
        req[i]=req[i]/2;
    }
    func(string(""),l-1);
}
