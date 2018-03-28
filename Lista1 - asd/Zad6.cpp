int Zad_6(double x[], int n)
{
	int	k = x[n];
	//	aLGORYTM Z KSIAZKI MACIEJA SYSLO - ALGORYTMY - MOZLIWOSC (3N/2)-2 - DZIAL 5.5
	if (n % 2 == 1)
	{n--;}
	double Max, Min;
	int i, y;
	i = 1;
	int porow = 0;
	while (i <= n)
	{
	if (x[i - 1] > x[i])
	{
		y = x[i - 1];
		x[i - 1] = x[i];
		x[i] = y;
		
		}
	i = i + 2;
	porow++;
	}

	
	Min = x[0];
	Max = x[1];
	i = 3;
	while (i <= n)
	{
		
		if (Min > x[i - 1])
		{
		
			Min = x[i - 1];
		}
		if (Max < x[i])
		{
			Max = x[i];
		}
		porow += 2;
		i += 2;
	}
		if (k >= Max)
		{
			Max = k;
		}
		if (k <= Min)
		{
			 Min = k;
		}
	
//	cout << porow;
	cout << Min << " " << Max << endl;
	return (Min,Max);
}