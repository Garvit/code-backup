#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdlib>
using namespace std;
int r, c ;
char **board ;
int **flag;
int ***parent;

struct cell
{
	int x;
	int y;
	int steps;
	int heuristic ;
	struct cell *parent ;
};

struct comp
{
	bool operator () ( struct cell a,  struct cell b)
	{
		return (a.steps + a.heuristic) > (b.steps  + b.heuristic)  ;
	}
};

int counter = 0;
void printPath(int x, int y)
{
	if(x == -1 || y == -1)
		return;
	printPath(parent[x][y][0], parent[x][y][1]) ;
	cout<<x <<" "<< y << endl ;
}

void init(struct cell &a, int x, int y, int s, int h, struct cell *p)
{
	a.x = x;
	a.y = y;
	a.steps = s;
	a.heuristic = h;
	a.parent = p;
}

int main(void) {
	int px, py, fx, fy ;
	int i, j;

	cin >> px >> py ;
	cin >> fx >> fy ;
	cin >> r >> c ;

	board = new char*[r] ;
	flag = new int*[r] ;
	parent = new int**[r];
	for(i=0; i<r ; ++i)
	{
		board[i] = new char [c] ;
		flag[i] = new int [c] ;
		parent[i] = new int *[c];
		for(j=0;j<c;++j)
		{
			cin >> board[i][j] ;
			flag[i][j] = 0;
			parent[i][j] = new int [2];
			parent[i][j][0] = -1;
			parent[i][j][1] = -1;
		}
	}
	struct cell start;
	init(start, px, py, 0, abs(px-fx)+abs(py-fy), &start);
	priority_queue<struct cell, vector<struct cell>, comp> q;

	q.push(start);
	flag[px][py] = 1;
	bool found = false ;
	int count =0;

	struct cell temp;

	while(!found )//&& count < 20 )
	{
		count++;
		temp = q.top();
		q.pop();
		if(temp.x == fx && temp.y == fy)
		{
			found = true ;
		}

//	cout<<count << " "<< temp.x <<" " <<temp.y <<" "<<temp.steps << " "<<parent[temp.x][temp.y][0] <<" " <<parent[temp.x][temp.y][1] <<endl;

		if( temp.x > 0 && flag[temp.x -1][temp.y] == 0 && board[temp.x-1][temp.y] !='%')
		{
			flag[temp.x-1][temp.y] = 1;
			parent[temp.x-1][temp.y][0] = temp.x;
			parent[temp.x-1][temp.y][1] = temp.y;

			struct cell left = * new struct cell;
			init(left, temp.x-1,temp.y, temp.steps+1,abs(temp.x-1-fx)+abs(temp.y-fy), &temp);
			q.push(left);
		}
		if( temp.y > 0 && flag[temp.x ][temp.y-1] == 0  && board[temp.x][temp.y-1] !='%')
		{
			flag[temp.x][temp.y-1] = 1;
			parent[temp.x][temp.y-1][0] = temp.x;
			parent[temp.x][temp.y-1][1] = temp.y;
			struct cell up = * new struct cell;
			init(up, temp.x,temp.y-1, temp.steps+1,abs(temp.x-fx)+abs(temp.y-1-fy), &temp);
			q.push(up);
		}
		if( temp.x < r-1 && flag[temp.x +1][temp.y] == 0  && board[temp.x+1][temp.y] !='%')
		{
			struct cell right = * new struct cell;
			parent[temp.x+1][temp.y][0] = temp.x;
			parent[temp.x+1][temp.y][1] = temp.y;
			flag[temp.x+1][temp.y] = 1;
			init(right, temp.x+1,temp.y, temp.steps+1,abs(temp.x+1-fx)+abs(temp.y-fy), &temp);
			q.push(right);
		}if( temp.y < c-1 && flag[temp.x][temp.y+1] == 0 && board[temp.x][temp.y+1] !='%')
		{
			flag[temp.x][temp.y+1] = 1;
			parent[temp.x][temp.y+1][0] = temp.x;
			parent[temp.x][temp.y+1][1] = temp.y;
			struct cell down = * new struct cell;
			init(down, temp.x,temp.y+1, temp.steps+1,abs(temp.x-fx)+abs(temp.y+1-fy), &temp);
			q.push(down);
		}
	}
	cout << temp.steps << endl;
	count = 0;
	int x = temp.x ;
	int y = temp.y ;

	printPath(x, y);

	return 0;
}
