#include<iostream>
#include<stack>
using namespace std;

int output[10][2];
int arr[10][2];
int curr_min=10,curr=0,n,k;
int state[10];
int end[10];
stack<int> pegs[6];

bool check(int a[],int b[])
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i]) return false;
    }
    return true;
}
void backtrack()
{
    if(curr>=curr_min) return;

    if(check(state,end))
    {
        if(curr<curr_min)
        {
            curr_min=curr;
            for(int i=0;i<curr;i++)
            {
                output[i][0]=arr[i][0];
                output[i][1]=arr[i][1];
            }
            return;
        }
    }
    for(int i=1;i<=k;i++)
    {
        if(pegs[i].size()!=0)
        {
            int disk=pegs[i].top();
            for(int j=1;j<=k;j++)
            {
                if(j!=i && (pegs[j].size()==0 || pegs[j].top()>disk))
                {
                    arr[curr][0]=i;
                    arr[curr][1]=j;
                    curr++;
                    pegs[i].pop();
                    pegs[j].push(disk);
                    state[disk]=j;
                    backtrack();
                    curr--;
                    pegs[j].pop();
                    pegs[i].push(disk);
                    state[disk]=i;


                }
            }
        }
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>state[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>end[i];
    }
    for(int i=n;i>0;i--)
    {
        pegs[state[i]].push(i);
    }
    backtrack();
    cout<<curr_min<<endl;
    for(int i=0;i<curr_min;i++)
    {
        cout<<output[i][0]<<" "<<output[i][1]<<endl;
    }
    return 0;
}
