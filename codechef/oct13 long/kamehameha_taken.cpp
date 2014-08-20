#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

#define maxM 10007
using namespace std;

struct bipartite_graph
{
	int V1, V2;
	map<int, vector<int> > L;
	map<int, int> visited;
	map<int, int> match;

	bipartite_graph(int MAX_V1, int MAX_V2)
	{
		V1 = MAX_V1;
		V2 = MAX_V2;

	}

	void clear(int _V1, int _V2)
	{
		V1 = _V1;
		V2 = _V2;
		L.clear();
		visited.clear();
		match.clear();
	}

	void add_edge(int v1, int v2)
	{
		L[v1].push_back(v2);

	}

	bool dfs(int u)
	{
		for (int i = L[u].size() - 1; i >= 0; --i)
		{
			int v = L[u][i];
			if (visited[v] == 0)
			{
				visited[v] = 1;
				if (match[v] == 0 || dfs(match[v]))
				{
					match[v] = u;
					return true;
				}
			}
		}
		return false;
	}

	int maximum_matching()
	{
		int ans = 0;
		//fill(match,match+V2,-1);
		match.clear();

		for (std::map<int, vector<int> >::iterator it = L.begin(); it != L.end(); ++it)
		{
			visited.clear();
			//fill(visited,visited+V2,false);
			ans += dfs(it->first);
		}

	return ans;
}
};

int main()
{
	int T, n, r, c;
	bipartite_graph G(maxM, maxM);

	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc)
	{
		scanf("%d", &n);

		G.clear(maxM, maxM);

		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &r, &c);
			G.add_edge(r, c);
		}

		printf("%d\n", G.maximum_matching());
	}

	return 0;
}
