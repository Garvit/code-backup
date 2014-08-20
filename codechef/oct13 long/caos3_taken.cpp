#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

#define F(i,a,n) for(int i=(a);i<(n);++i)
#define S(x) scanf("%d",&x)
#define M(x,i) memset(x,i,sizeof(x))

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

char s[25][25];
bool a[25][25];
int n,m;

int dp[21][21][21][21];

bool isCPC(int x,int y) {
    F(i,0,4) {
        F(j,1,3) {
            int nx = x + dx[i]*j;
            int ny = y + dy[i]*j;
            if ( nx < 0 || ny < 0 || nx >= n || ny >= m )
                return false;
            if ( s[nx][ny] == '#' ) return false;
        }
    }
    return true;
}

int grundy(int sx,int sy,int ex,int ey) {
    if ( sx > ex || sy > ey ) return 0;
    int &res = dp[sx][sy][ex][ey];
    if ( res != -1 ) return res;
    res = 0;
    bool mex[300] = {0};
    F(i,sx,ex+1) {
        F(j,sy,ey+1) {
            if ( a[i][j] ) {
                int g1 = grundy(sx,sy,i-1,j-1);
                int g2 = grundy(i+1,j+1,ex,ey);
                int g3 = grundy(sx,j+1,i-1,ey);
                int g4 = grundy(i+1,sy,ex,j-1);
                mex[g1^g2^g3^g4] = true;
            }
        }
    }
    while ( mex[res] ) res++;
    return res;
}

int main() {
   int t; S(t);
    while ( t-- ) {
        M(dp,-1);
        S(n); S(m);
        F(i,0,n) scanf("%s",s[i]);
        F(i,0,n) { F(j,0,m) {
            if ( s[i][j] == '#' ) {
                // cout << a[i][j] << " ";
                a[i][j] = 0; continue;
            }
            a[i][j] = isCPC(i,j);
            } }
        int ans = grundy(2,2,n-3,m-3);
        printf("%s\n",(ans?"Asuna":"Kirito"));
    }
    return 0;
}
