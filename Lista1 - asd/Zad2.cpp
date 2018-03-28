double func(double x)
{
	return pow(x, 3) - pow(x, 2) + 2;	
}
double Zad_2(double a, double b)
{
	if (func(a)* func(b) >= 0)
	{
		return 0;
	}
	double c = a;

	while ((b - a) >= DBL_EPSILON)
	{
		c = (a + b) / 2;
		if (func(c) == 0.0)
		{
			break;
		}
		else if (func(c)*func(a) < 0)
			b = c;
		else
			a = c;
	}
	//cout << c;
}