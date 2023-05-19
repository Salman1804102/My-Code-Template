//Codeforces - Round Dance, Link : https://codeforces.com/contest/1833/problem/E

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define fastio  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define print(v) for(auto it : v) cout << it << ' '; cout << endl;
#define valid(i, j, n, m) (i >= 0 && i < n && j >= 0 && j < m)
#define all(x) (x).begin(), (x).end()
#define revall(x) (x).rbegin(), (x).rend()
#define kase(i) cout << "Case " << i << ": ";
#define debug(x) cout << #x << "--> " << x << endl;
#define int long long
#define pii pair<int, int>
#define ppii pair<pii, int>
#define fi first
#define se second
#define inf 1e18
#define set(x, i) (x | (1 << i))
#define check(x, i) (x & (1 << i))
#define lcm(a, b) ((a  * b) / __gcd(a, b))

using namespace std;
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order and order_of_key
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using o_mset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order and order_of_key

const int mod = 1e9 + 7;
const int N = 2e5 + 5;
vector<int>graph[N];
int vis[N], iscycle = 0;
void dfs(int src, int parent)
{
    if (vis[src] == 2) return;

    if (vis[src] == 1)
    {
        iscycle = 1;
        return;
    }

    vis[src] = 1;
    for (auto it : graph[src])
    {
        if (it != parent) dfs(it, src);
    }
    vis[src] = 2;
}
main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int tc; cin >> tc;
    while (tc--)
    {
        int n; cin >> n;
        map<pii, int>mp;
        for (int i = 1; i <= n; i++)
        {
            int u = i;
            int v; cin >> v;
            if (v < u) swap(v, u);
            if (mp[pii(v, u)] == 0)
            {
                graph[u].push_back(v);
                graph[v].push_back(u);
                mp[pii(u, v)] = 1;
            }
        }
        int component = 0, cycle = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                component += 1;
                dfs(i, -1);
                cycle += iscycle;
                iscycle = 0;
            }
        }
        if (cycle)
        {
            if (cycle != component) cout << cycle + 1 << ' ' << component << endl;
            else cout << component << ' ' << component << endl;
        }
        else cout << 1 << ' ' << component << endl;
        for (int i = 0; i <= n; i++)
        {
            graph[i].clear();
            vis[i] = 0;
        }
    }
}
