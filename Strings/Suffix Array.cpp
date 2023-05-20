//from cp algorithm
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

vector<int> sort_cyclic_shifts(string const& s)
{
	int n = s.size();
	const int alphabet = 256;
	vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
	for (int i = 0; i < n; i++)
		cnt[s[i]]++;
	for (int i = 1; i < alphabet; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++)
		p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for (int i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i - 1]])
			classes++;
		c[p[i]] = classes - 1;
	}
	vector<int> pn(n), cn(n);
	for (int h = 0; (1 << h) < n; ++h)
	{
		for (int i = 0; i < n; i++)
		{
			pn[i] = p[i] - (1 << h);
			if (pn[i] < 0)
				pn[i] += n;
		}
		fill(cnt.begin(), cnt.begin() + classes, 0);
		for (int i = 0; i < n; i++)
			cnt[c[pn[i]]]++;
		for (int i = 1; i < classes; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for (int i = 1; i < n; i++)
		{
			pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
			pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
			if (cur != prev)
				++classes;
			cn[p[i]] = classes - 1;
		}
		c.swap(cn);
	}
	return p;
}
vector<int> suffix_array_construction(string s)
{
	s += "$";
	vector<int> sorted_shifts = sort_cyclic_shifts(s);
	sorted_shifts.erase(sorted_shifts.begin());
	return sorted_shifts;
}
main()
{
	fastio;
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	string s; cin >> s;
	vector<int>p = suffix_array_construction(s);
	//print(p);
	for (int i = p[0]; i < s.size(); i++) cout << s[i];
	for (int i = 0; i < p[0]; i++) cout << s[i];
	cout << endl;
}
