// this code calculates the number of different substrings
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
int count_unique_substrings(string const &s)
{
	int n = s.size();
	const int p = 31;
	const int m = 1e9 + 9;
	vector<int>p_pow(n);
	p_pow[0] = 1;
	for (int i = 1; i < n; i++) p_pow[i] = (p_pow[i - 1] * p) % m;
	vector<int>h(n + 1, 0);
	for (int i = 0; i < n; i++) h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
	int cnt = 0;
	for (int l = 1; l <= n; l++)
	{
		unordered_set<int>hs;
		for (int i = 0; i <= n - l; i++)
		{
			int cur_h = (h[i + l] + m - h[i]) % m;
			cur_h = (cur_h * p_pow[n - i - 1]) % m;
			hs.insert(cur_h);
		}
		cnt += hs.size();
	}
	return cnt;
}
main()
{
	fastio;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	string s; cin >> s;
	cout << count_unique_substrings(s) << endl;
}
