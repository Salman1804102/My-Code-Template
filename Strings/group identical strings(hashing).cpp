vector<vector<int>> group_identical(vector<string>const & s)
{
	int n = s.size();
	vector<pii>hashes(n);
	for (int i = 0; i < n; i++) hashes[i] = {compute_hash(s[i]), i};
	sort(all(hashes));
	vector<vector<int>>groups;
	for (int i = 0; i < n; i++)
	{
		if (i == 0 || hashes[i].first != hashes[i - 1].first)
			groups.emplace_back();
		groups.back().push_back(hashes[i].second);
	}
	return groups;
}
