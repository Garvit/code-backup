#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define MAXINT 1000001
#define MAX 49

int graph[MAX][MAX];
int key[MAX];

bool visit[MAX];
bool checked[MAX];
int maxe;
int findmax()
{
    priority_queue<pair<int,int> > queue;
    pair <int ,int> temp;
    int maxind1=0,maxind2=0,maxind=0;
    for(int i=0;i<=maxe;i++)
    {
        key[i]=0;
        checked[i]=false;
        visit[i]=false;
    }

    int i,j;
    for(int k=0;k<=maxe;k++)
    {
        if(!checked[k]){
            maxind2=maxind1;
        queue=priority_queue<pair<int,int> >();
        queue.push(pair<int,int> (key[k],k));
    while(!queue.empty())
    {
        temp=queue.top();
        queue.pop();
        i=temp.second;
        if(!visit[i])
        {
            visit[i]=true;

            for(j=0;j<=maxe;j++)
            {
                //cout<<j<<" "<<graph[i][j]<<" "<<key[j]<<endl;
                if(!visit[j] && graph[i][j]>0 && key[i]+graph[i][j]>key[j])
                {
                    checked[j]=true;
                    key[j]=key[i]+graph[i][j];
                    if(k>maxind2)
                        key[j]+=key[maxind2];
                    queue.push(pair<int,int>(key[j],j));
                    if(j>maxind1)
                    {
                        maxind1=j;
                    }
                    //cout<<j<<endl;
                }
            }


            if(i==maxe)
                break;
        }
    }
    maxind=key[maxind1]>key[maxind2]?maxind1:maxind2;
    memset(visit, false, sizeof(visit));
    }
    }
    return maxind;
}


int main()
{
    int t,n,s,e,c;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        maxe=0;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>s>>e>>c;
            graph[s][e]=c;
            if(e>maxe)
            {
                maxe=e;
            }
        }
        //cout<<maxe<<" "<<graph[1][5];
        int m=findmax();
        cout<<key[m]<<endl;
        memset(graph, 0, sizeof(graph));

    }
    return 0;
}
