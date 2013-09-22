#include <iostream>
#include <vector>
#include<queue>
#include<utility>
using namespace std;

bool visited[30][30];
int parent[30][30][2];
queue<pair<int,int> > points;
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
    int curx,cury;
    points.push(pair<int,int>(pacman_r,pacman_c));
    visited[pacman_r][pacman_c]=true;
    while(1)
    {
        pair<int,int> p=points.front();
        points.pop();
        explored.push_back(p);
        curx=p.first;cury=p.second;

        if(curx==food_r && cury==food_c)
            break;
        if(curx!=0 && grid[curx-1][cury]!='%' && visited[curx-1][cury]==false) {
            points.push(pair<int,int>(curx-1,cury));
            visited[curx-1][cury]=true;
            parent[curx-1][cury][0]=curx;
            parent[curx-1][cury][1]=cury;
        }
        if(cury!=0 && grid[curx][cury-1]!='%' && visited[curx][cury-1]==false){
            points.push(pair<int,int>(curx,cury-1));visited[curx][cury-1]=true;
            parent[curx][cury-1][0]=curx;
            parent[curx][cury-1][1]=cury;
        }
        if(cury<c-1 && grid[curx][cury+1]!='%' && visited[curx][cury+1]==false){
            points.push(pair<int,int>(curx,cury+1));visited[curx][cury+1]=true;
            parent[curx][cury+1][0]=curx;
            parent[curx][cury+1][1]=cury;
            }
        if(curx<r-1 && grid[curx+1][cury]!='%' && visited[curx+1][cury]==false){
            points.push(pair<int,int>(curx+1,cury));visited[curx+1][cury]=true;
            parent[curx+1][cury][0]=curx;
            parent[curx+1][cury][1]=cury;
            }
    }
    cout<<explored.size()<<endl;
    for(int i=0;i<explored.size();i++)
    {
        pair<int,int> p=explored[i];
        cout<<p.first<<" "<<p.second<<endl;

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

