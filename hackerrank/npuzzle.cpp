#include <iostream>
#include<stdlib.h>
#include <vector>
#include<queue>
#include<utility>
#include<set>
using namespace std;
int k=5;

struct move
{
    vector<vector<int> > conf;
    struct move* parent;
    string str;
    int value()
    {
        int val1=0,v,c,r;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                v=conf[i][j];
                r=v/k;
                c=v-r*k;
                val1+=abs(r-i)+abs(c-j);
            }
        }
        return val1;
    }
};
class comparision
{
    public: bool operator()(struct move* m1,struct move* m2)
    {
        int val1=0,val2=0,v,c,r;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                v=m1->conf[i][j];
                r=v/k;
                c=v-r*k;
                val1+=abs(r-i)+abs(c-j);
                v=m2->conf[i][j];
                r=v/k;
                c=v-r*k;
                val2+=abs(r-i)+abs(c-j);
            }
        }
        return val1>val2;
    }
};
set<vector<vector<int> > > visited;
priority_queue<move*, vector<move*> , comparision> pq;
void print(struct move* m,int size)
{
    if(m->parent==NULL){
        cout<<size<<endl;
        /*for(int i=0;i<k;i++)
        {
        for(int j=0;j<k;j++)
        {
            cout<<m->conf[i][j];
        }
        cout<<endl;
        }*/
        return;}

    print((m->parent),size+1);
    cout<<m->str<<endl;
    /*for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            cout<<m->conf[i][j];
        }
        cout<<endl;
    }*/
    //cout<<m->parent<<" "<<m->parent->parent;
}
void next(vector<vector<int> > initial)
{
    struct move i;
    i.conf=initial;
    i.parent=NULL;
    pq.push(&i);
    visited.insert(initial);
    while(1)
    {
        struct move* m=pq.top();
        //cout<<m<<endl;
        pq.pop();
        //cout<<m->value()<<endl;
        if(m->value()==0){
            print(m,0);break;}
        int zi,zj,flag=0;
        vector<vector<int> > v=m->conf;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(v[i][j]==0){
                    zi=i;zj=j;flag=1;break; }
            }
            if(flag==1) break;
        }
        //cout<<"zi "<<zi<<" zj "<<zj<<endl;
        if(zi>0)
        {
            vector<vector<int> > conf1(k);
            for(int t1=0;t1<k;t1++)
            {
                for(int t2=0;t2<k;t2++)
                {
                    conf1[t1].push_back(v[t1][t2]);
                }
            }
            conf1[zi][zj]=conf1[zi-1][zj];
            conf1[zi-1][zj]=0;
            if(visited.find(conf1)==visited.end()){
            struct move* m1=new move();
            m1->conf=conf1;
            m1->parent=m;
            m1->str="UP";
            pq.push(m1);
            visited.insert(conf1);
            }
        }
        if(zj>0)
        {
            vector<vector<int> > conf1(k);
            for(int t1=0;t1<k;t1++)
            {
                for(int t2=0;t2<k;t2++)
                {
                    conf1[t1].push_back(v[t1][t2]);
                }
            }
            conf1[zi][zj]=conf1[zi][zj-1];
            conf1[zi][zj-1]=0;
            if(visited.find(conf1)==visited.end()){
            struct move* m1=new move();
            m1->conf=conf1;
            m1->parent=m;
            m1->str="LEFT";
            pq.push(m1);
            visited.insert(conf1);
            }
        }
        if(zj<k-1)
        {
            vector<vector<int> > conf1(k);
            for(int t1=0;t1<k;t1++)
            {
                for(int t2=0;t2<k;t2++)
                {
                    conf1[t1].push_back(v[t1][t2]);
                }
            }
            conf1[zi][zj]=conf1[zi][zj+1];
            conf1[zi][zj+1]=0;
            if(visited.find(conf1)==visited.end()){
            struct move* m1=new move();
            m1->conf=conf1;
            m1->parent=m;
            m1->str="RIGHT";
            pq.push(m1);
            visited.insert(conf1);
            }
        }
        if(zi<k-1)
        {
            vector<vector<int> > conf1(k);
            for(int t1=0;t1<k;t1++)
            {
                for(int t2=0;t2<k;t2++)
                {
                    conf1[t1].push_back(v[t1][t2]);
                }
            }
            conf1[zi][zj]=conf1[zi+1][zj];
            conf1[zi+1][zj]=0;
            if(visited.find(conf1)==visited.end()){
            struct move* m1=new move();
            m1->conf=conf1;
            m1->parent=m;
            m1->str="DOWN";
            pq.push(m1);
            visited.insert(conf1);
            }
        }

    }
}
int main()
{
    cin>>k;
    vector<vector<int> > ini(k);
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            int v;cin>>v;
            ini[i].push_back(v);
        }
    }
    next(ini);
    return 0;
}
