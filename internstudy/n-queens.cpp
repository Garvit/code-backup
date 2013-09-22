#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

vector<int> ans;
bool row_visit[10];
int num=0;
bool check(int n,int col,int row)
{
    for(int i=0;i<ans.size();i++)
    {
        int r=ans[i];
        if(abs(row-r)==(col-i)) return false;
    }
    return true;
}
void print()
{
  for(int i=0;i<ans.size();i++)
  {
      cout<<"row: "<<ans[i]<<" col: "<<i<<endl;
  }
    //exit(0);
}
void backtrack(int n,int col)
{
    if(ans.size()==n)
    {
        //print();
        num++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(row_visit[i]==0 && check(n,col,i))
        {
            ans.push_back(i);
            row_visit[i]=1;
            backtrack(n,col+1);
            row_visit[i]=0;
            ans.pop_back();
        }
    }
}
int main()
{
    int n;
    cin>>n;
    backtrack(n,0);
    cout<<num<<endl;
}
