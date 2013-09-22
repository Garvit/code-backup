#include <iostream>
#include<stdlib.h>
#include <vector>
#include<queue>
#include<utility>
using namespace std;


class comparision
{
    public: bool operator()(pair<pair<int,int>,int > p1, pair<pair<int,int>,int > p2){
        return (p1.second > p2.second);
    }
};

bool visited[100][100];
int parent[100][100][2];
int depth[100][100];
priority_queue<pair<pair<int,int>,int >, vector<pair<pair<int,int>,int > >, comparision > points;
//queue<pair<pair<int,int>,int> > points;
void printdist(int pacr,int pacc,int r,int c,int size)
{
    if(r==pacr && c==pacc)
    {
        cout<<size<<endl;
        cout<<r<<" "<<c<<endl;
        return;
    }
    printdist(pacr,pacc,parent[r][c][0],parent[r][c][1],size+1);
    cout<<r<<" "<<c<<endl;
}
int manhattan(int r1,int c1,int r2,int c2)
{
    return abs(r1-r2)+abs(c1-c2);
}
void nextMove( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid){
    int curx,cury,cost=manhattan(food_r,food_c,pacman_r,pacman_c),dep=0;
    points.push(pair<pair<int,int>,int >(pair<int,int>(pacman_r,pacman_c),cost));
    visited[pacman_r][pacman_c]=true;
    while(1)
    {
        pair<pair<int,int>,int > p1=points.top();
        pair<int,int> p=p1.first;
        int c=p1.second,temp=0,c1;
        points.pop();
        curx=p.first;cury=p.second;
        dep++;
        if(curx==food_r && cury==food_c)
            break;
        //cout<<curx<<" "<<cury<<endl;

        if(curx!=0 && grid[curx-1][cury]!='%' && visited[curx-1][cury]==false) {
            if(grid[curx-1][cury]=='.') temp=-1;
            c1=manhattan(curx-1,cury,food_r,food_c);
            points.push(pair<pair<int,int>,int >(pair<int,int>(curx-1,cury),c1+dep+temp));
            visited[curx-1][cury]=true;
            parent[curx-1][cury][0]=curx;
            parent[curx-1][cury][1]=cury;
            temp=0;
        }
        if(cury!=0 && grid[curx][cury-1]!='%' && visited[curx][cury-1]==false){
            if(grid[curx][cury-1]=='.') temp=-1;
            c1=manhattan(curx,cury-1,food_r,food_c);
            points.push(pair<pair<int,int>,int >(pair<int,int>(curx,cury-1),c1+dep+temp));
            visited[curx][cury-1]=true;
            parent[curx][cury-1][0]=curx;
            parent[curx][cury-1][1]=cury;
            temp=0;
        }
        if(cury<c-1 && grid[curx][cury+1]!='%' && visited[curx][cury+1]==false){
            if(grid[curx][cury+1]=='.') temp=-1;
            c1=manhattan(curx,cury+1,food_r,food_c);
            points.push(pair<pair<int,int>,int >(pair<int,int>(curx,cury+1),c1+dep+temp));
            visited[curx][cury+1]=true;
            parent[curx][cury+1][0]=curx;
            parent[curx][cury+1][1]=cury;
            temp=0;
            }
        if(curx<r-1 && grid[curx+1][cury]!='%' && visited[curx+1][cury]==false){
            if(grid[curx+1][cury]=='.') temp=-1;
            c1=manhattan(curx+1,cury,food_r,food_c);
            points.push(pair<pair<int,int>,int >(pair<int,int>(curx+1,cury),c1+dep+temp));
            visited[curx+1][cury]=true;
            parent[curx+1][cury][0]=curx;
            parent[curx+1][cury][1]=cury;
            temp=0;
            }
    }

    printdist(pacman_r,pacman_c,food_r,food_c,0);
}

/* Tail starts here */
int main(void) {

    int r,c, pacman_r, pacman_c, food_r, food_c;

    cin >> pacman_r >> pacman_c;
    cin >> food_r >> food_c;
    cin >> r >> c;

    vector <string> grid;

    for(int i=0; i<r; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove( r, c, pacman_r, pacman_c, food_r, food_c, grid);

    return 0;
}


