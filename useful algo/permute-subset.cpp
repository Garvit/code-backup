#include<iostream>
#include<cstring>

using namespace std;

void permute(string a,string str)
{
    if(str.length()==1)
    {
        cout<<a<<str<<endl;
        return;
    }

    for(int i=0;i<str.length();i++)
    {
        char temp=str[0];
        str[0]=str[i];
        str[i]=temp;
        //a=a+str[0];
        permute(a+str[0],str.substr(1));
    }

}
void subset(string a,string str)
{
    if(str.length()==0) return;

    int l=str.length();
    for(int i=0;i<l;i++)
    {
        cout<<a<<str[i]<<endl;
        subset(a+str[i],str.substr(i+1));
    }
}
int main()
{
    string s="gar";
    permute("",s);
    return 0;
}
