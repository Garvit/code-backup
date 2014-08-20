#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxn = 50005;

int n, m;
vector <ii> neigh[Maxn];
int dist[Maxn];
int res;

int getRes()
{
    fill(dist, dist + Maxn, Inf); dist[1] = 0;
    priority_queue <ii> Q; Q.push(ii(-dist[1], 1));
    while (!Q.empty()) {
        int v = Q.top().second, d = -Q.top().first; Q.pop();
        if (dist[v] != d) continue;
        if (v == n) return d;
        for (int i = 0; i < neigh[v].size(); i++) {
            ii u = neigh[v][i];
            if (max(d, u.second) < dist[u.first]) {
                dist[u.first] = max(d, u.second); Q.push(ii(-dist[u.first], u.first));
            }
        }
    }
    return Inf;
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        neigh[a].push_back(ii(b, c)); neigh[b].push_back(ii(a, c));
    }
    res = getRes();
    if (res == Inf) printf("NO PATH EXISTS\n");
    else printf("%d\n", res);
    return 0;
}

