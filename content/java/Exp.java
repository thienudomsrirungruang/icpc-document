public static int exp(int a, int exp, int mod)
{
	int e = exp;
	if(e==0)
	{
		return 1;
	}
	long b = (long)(a);
	long ret = 1;
	while(e > 1)
	{
		if(e % 2 == 0)
		{
			e = e/2;
			b = (b*b)%mod;
		}
		else
		{
			ret = (ret*b)%mod;
			e = e/2;
			b = (b*b)%mod;
		}
	}
	b = (b*ret)%mod;
	return (int)(b);
}