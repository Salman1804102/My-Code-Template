void RodCutting(int A[], int n)
{
	memset(rodcut, 0, sizeof rodcut);
	for (int len = 1; len <= n; len++)
	{
		for (int cut = 1; cut <= len; cut++) rodcut[len] = max(rodcut[len], A[cut] + rodcut[len - cut]);
	}
}
