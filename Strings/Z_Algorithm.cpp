
//Problem : CF - Password
// In The Name of Almighty Allah
#include<bits/stdc++.h>
using namespace std;
#define             fastio              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define             ff                  first
#define             ss                  second
#define             int                 long long
#define             pb                  push_back
#define             pf                  push_front
#define             pii                 pair<int,int>
#define             debug(x)            cout << #x << " --->> " << x << endl;
#define             mod                 1000000007
#define             inf                 1e18
#define             clear(x)            memset(x,0,sizeof(x));
void Salman()
{
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

string Z_Algo(string pattern)
{
	int m = (int) pattern.size();

	vector<int>z(m);

	for (int i = 1, L = 0, R = 0; i < m; i++)
	{
		if (i <= R)
			z[i] = min(R - i + 1, z[i - L]);
		while (i + z[i] < m && pattern[z[i]] == pattern[z[i] + i])
			++z[i];
		if (i + z[i] - 1 > R)
			L = i, R = i + z[i] - 1;
	}

	vector<int>v;

	int len = 0;

	for (int i = 0; i < m; i++) v.push_back(z[i]);

	sort(v.begin(), v.end());

	for (int i = m - 1; i > 0; i--)
	{
		if (m - i == z[i])
		{
			int freq = v.end() - lower_bound(v.begin(), v.end(), z[i]);
			//debug(freq)
			if (freq >= 2)
			{
				len = z[i];
			}
		}
	}
	if (len)
	{
		string t = "";
		for (int i = 0; i < len; i++) t += pattern[i];
		return t;
	}
	else return "Just a legend";
}

main()
{
	//Salman();
	string s;
	cin >> s;
	cout << Z_Algo(s) << endl;
	//main();
}
