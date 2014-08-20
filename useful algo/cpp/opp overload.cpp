#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

string operator+(string a,string b)
{
    return b.append(a);
}
vector<int> operator+(vector<int> v,int a)
{
    for(int i=0;i<v.size();i++)
    {
        v[i]+=a;
    }
    return v;
}
int main()
{
    vector<int> arr(4,10);
    arr=arr+2;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
