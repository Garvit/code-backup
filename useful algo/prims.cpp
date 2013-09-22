#include<iostream>
#include<vector>
#include<queue>

using namespace std;
class comparision
{
    public: bool operator()(int a,int b)
    {
        return a>b;
    }
};

priority_queue<int, vector<int>, comparision> q;
int main()
{
    q.push(20);
    q.push(10);
    q.push(30);
    while(!q.empty())
    {
        cout<<q.top();
        q.pop();
    }
}


