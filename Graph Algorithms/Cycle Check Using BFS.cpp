#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int n, m, vis[101], parent[101];
vector<int>graph[101];
bool BFS(int src)
{
	for (int i = 1; i <= n; i += 1) vis[i] = 0, parent[i] = -1;
	vis[src] = true;
	queue<int>q;
	q.push(src);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (auto v : graph[u])
		{
			if (vis[v] == 0)
			{
				vis[v] = true;
				parent[v] = u;
				q.push(v);
			}
			else
			{
				if (v != parent[u]) return true;
			}
		}
	}
	return false;
}
int main()
{
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bool cycle = BFS(1);
	if (cycle) cout << "Yes, the graph contains the cycle" << endl;
	else cout << "The graph doesn't have any cycle" << endl;
	return 0;
}
