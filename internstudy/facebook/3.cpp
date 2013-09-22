#include<iostream>
#include<string.h>

using namespace std;
int arr[10][10];
bool filled[100];
int maxim;
int max(int a,int b)
{
    return a>b?a:b;
}
void help(int i,int j,int n)
{
    if(i>=0 && i<n && j>=0 && j<n) maxim=max(maxim,arr[i][j]);
}
int minpos(int i,int j,int n)
{
    maxim=0;
    help(i-1,j-1,n);
    help(i-1,j,n);
    help(i-1,j+1,n);
    help(i,j-1,n);
    help(i,j+1,n);
    help(i+1,j-1,n);
    help(i+1,j,n);
    help(i+1,j+1,n);
   // cout<<maxim<<endl;
    for(int k=maxim+1;k<=n*n;k++)
    {
        if(filled[k]==0) return k;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]!=0)
                filled[arr[i][j]]=1;
        }
    }
    int num;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            num=arr[i][j];
            if(arr[i][j]==0)
            {
                num=minpos(i,j,n);
            }
            filled[num]=1;
            cout<<num<<" ";
        }
        cout<<"\n";
    }
}
