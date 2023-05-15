void DivisorSieve()
{
	for (int i = 1; i <= 1000000; i++)
	{
		for (int j = i; j <= 1000000; j = j + i)
		{
			v[j].push_back(i);
		}
	}
}
