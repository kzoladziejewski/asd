double Zad_1_Bezrekurencji(double x, int n)
{	
	if (n < 0)
	{
		x = 1 / x;
		n = -n;
}
	if (n = 0)
	{
		return 0;
	}
	int y = 1;
	
	while (n > 1)
	{
		
		if (n % 2 == 0)
		{
			x = x *x;
			n = n / 2;
	
		}
		if (n % 2 == 1)
		{
			y = x*y;
			x = x*x;
			n = (n - 1) / 2;
		
		}

	}
	return x*y;
}
double Zad_1_Rekurencyjna(double x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n % 2 == 1)
	{
		return x * pow(Zad_1_Rekurencyjna(x, (n - 1) / 2), 2);
	}
	if (n % 2 == 0)
	{
		return pow(Zad_1_Rekurencyjna(x, (n / 2)), 2);
	}


}