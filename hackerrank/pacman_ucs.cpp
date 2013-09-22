#include <iostream>
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
//priority_queue<pair<pair<int,int>,int >, vector<pair<pair<int,int>,int > >, comparision > points;
queue<pair<pair<int,int>,int> > points;
vector<pair<int,int> > explored;
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

void nextMove( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid){
    int curx,cury,depth=0;
    points.push(pair<pair<int,int>,int >(pair<int,int>(pacman_r,pacman_c),0));
    visited[pacman_r][pacman_c]=true;
    while(1)
    {
        pair<pair<int,int>,int > p1=points.front();
        pair<int,int> p=p1.first;
        int d=p1.second;
        points.pop();
        if(d==depth && d!=0)
            break;
        explored.push_back(p);
        curx=p.first;cury=p.second;
        //cout<<curx<<" "<<cury<<endl;

        if(curx!=0 && grid[curx-1][cury]!='%' && visited[curx-1][cury]==false) {
            if(grid[curx-1][cury]=='.') depth=d+1;
            points.push(pair<pair<int,int>,int >(pair<int,int>(curx-1,cury),d+1));
            visited[curx-1][cury]=true;
            parent[curx-1][cury][0]=curx;
            parent[curx-1][cury][1]=cury;
        }
        if(cury!=0 && grid[curx][cury-1]!='%' && visited[curx][cury-1]==false){
            if(grid[curx][cury-1]=='.') depth=d+1;
            points.push(pair<pair<int,int>,int >(pair<int,int>(curx,cury-1),d+1));
            visited[curx][cury-1]=true;
            parent[curx][cury-1][0]=curx;
            parent[curx][cury-1][1]=cury;
        }
        if(cury<c-1 && grid[curx][cury+1]!='%' && visited[curx][cury+1]==false){
            if(grid[curx][cury+1]=='.') depth=d+1;
            points.push(pair<pair<int,int>,int >(pair<int,int>(curx,cury+1),d+1));
            visited[curx][cury+1]=true;
            parent[curx][cury+1][0]=curx;
            parent[curx][cury+1][1]=cury;
            }
        if(curx<r-1 && grid[curx+1][cury]!='%' && visited[curx+1][cury]==false){
            if(grid[curx+1][cury]=='.') depth=d+1;
            points.push(pair<pair<int,int>,int >(pair<int,int>(curx+1,cury),d+1));
            visited[curx+1][cury]=true;
            parent[curx+1][cury][0]=curx;
            parent[curx+1][cury][1]=cury;
            }
    }
    /*cout<<explored.size()<<endl;
    for(int i=0;i<explored.size();i++)
    {
        pair<int,int> p=explored[i];
        cout<<p.first<<" "<<p.second<<endl;

    }*/
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


