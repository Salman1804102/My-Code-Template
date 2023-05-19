//Problem CSES - Word Combination
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

using namespace std;
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order and order_of_key
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using o_mset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order and order_of_key

const int mod = 1e9 + 7;
const int N = 1e6 + 5;

int cnt = 0, Trie[N][26], endmark[N], dp[5001];

void Insert(string s)
{
	int n = s.size();
	int curr = 0;
	for (int i = 0; i < n; i++)
	{
		int id = s[i] - 'a';
		if (Trie[curr][id] == 0) Trie[curr][id] = ++cnt;
		curr = Trie[curr][id];
	}
	endmark[curr] = 1;
}
main()
{
	fastio;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int tc;
	tc = 1;
	while (tc--)
	{
		string s; cin >> s;
		int n = s.size();
		int q; cin >> q;
		for (int i = 1; i <= q; i++)
		{
			string temp; cin >> temp;
			Insert(temp);
		}
		dp[n] = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			int curr = 0, ans = 0;
			for (int j = i; j < n; j++)
			{
				if (Trie[curr][s[j] - 'a'] == 0) break;

				curr = Trie[curr][s[j] - 'a'];
				if (endmark[curr])
				{
					ans = (ans + dp[j + 1] % mod) % mod;
				}
			}
			dp[i] = ans;
		}
		cout << dp[0] << endl;
	}
}
