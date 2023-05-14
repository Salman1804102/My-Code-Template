string deci_to_bin(int n)
{
	string res = "";
	while (n)
	{
		int r = n % 2;
		res += (r + '0');
		n /= 2;
	}
	int sz = 31 - (int)res.size();
	for (int i = 1; i <= sz; i++) res += '0';
	// debug(res);
	reverse(res.begin(), res.end());
	return res;
}
