int compute_hash(string const& s)
{
	const int p = 31;
	const int m = 1e9 + 9;
	int hash_value = 0;
	int p_pow = 1;
	for (char ch : s)
	{
		hash_value = (hash_value + (ch - 'a' + 1) * p_pow) % mod;
		p_pow = (p_pow * p) % mod;
	}
	return hash_value;
}
