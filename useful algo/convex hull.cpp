#include<stdio.h>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

struct point
{
    int x,y;
};
point p0;

point nextToTop(stack<point> &s)
{
    point p=s.top();
    s.pop();
    point r=s.top();
    s.push(p);
    return r;
}
void swap(point &p1,point &p2)
{
    point temp=p1;
    p1=p2;
    p2=temp;
}
//0:collinear,1:anticlockwise,-1:clockwise
int orientation(point p,point q,point r)
{
    int val=(q.x-p.x)*(r.y-q.y)-(q.y-p.y)*(r.x-q.x);
    if(val==0) return 0;
    return val>0?1:-1;
}
int dist(point p1,point p2)
{
    return (p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y);
}
bool compare(point p1,point p2)
{
    int o=orientation(p0,p1,p2);
    if(o==0)
    {
        return (dist(p0,p1)<=dist(p0,p2))?true:false;
    }
    return (o==1)?true:false;
}
void ConvexHull(point p[],int n)
{
    int min=0,ymin=p[0].y;
    for(int i=1;i<n;i++)
    {
        if(p[i].y>ymin || (p[i].y==ymin && p[i].x<p[min].x))
        {
            ymin=p[i].y;
            min=i;
        }
    }
    swap(p[0],p[min]);
    p0=p[0];
    sort(p+1,p+n,compare);
    stack<point> s;
    s.push(p[0]);
    s.push(p[1]);
    s.push(p[2]);
    for(int i=3;i<n;i++)
    {
        while(orientation(nextToTop(s),s.top(),p[i])!=1)
            s.pop();
        s.push(p[i]);
    }
    while(!s.empty())
    {
        point pt=s.top();
        cout<<pt.x<<","<<pt.y<<endl;
        s.pop();
    }
}

int main()
{
    point p[]={{0,3},{1,1},{2,2},{4,4},{0,0},{1,2},{3,1},{3,3}};
    ConvexHull(p,8);
    return 0;
}
