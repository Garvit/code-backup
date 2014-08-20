#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

string f[30];
bool mon[30][30];
int memo[30][30][30][30];

int H, W;

bool free(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W && f[x][y] == '^';
}

int dp(int lx, int rx, int ly, int ry) {
    if (memo[lx][rx][ly][ry] >= 0) {
        return memo[lx][rx][ly][ry];
    }
    bool can[100] = {};
    for (int x = lx; x < rx; ++x) {
        for (int y = ly; y < ry; ++y) {
            if (mon[x][y]) {
                can[dp(lx, x, ly, y) ^ dp(x + 1, rx, ly, y) ^ dp(lx, x, y + 1, ry) ^ dp(x + 1, rx, y + 1, ry)] = true;
            }
        }
    }
    int i = 0;
    while (can[i]) ++i;
    return memo[lx][rx][ly][ry] = i;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int T;
    cin >> T;
    while (T-->0) {
        cin >> H >> W;
        for (int i = 0; i < H; ++i) {
            cin >> f[i];
        }
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                mon[i][j] = free(i, j);
                for (int d = 0; d < 4; ++d) {
                    for (int l = 1; l <= 2; ++l) {
                        mon[i][j] &= free(i + dx[d] * l, j + dy[d] * l);
                    }
                }
            }
        }
        for (int i = 0; i <= H; ++i) {
            for (int j = 0; j <= H; ++j) {
                for (int k = 0; k <= W; ++k) {
                    for (int l = 0; l <= W; ++l) {
                        memo[i][j][k][l] = -1;
                    }
                }
            }
        }
        int res = dp(0, H, 0, W);
        cout << (res ? "Asuna" : "Kirito") << '\n';
    }

	return 0;
}
