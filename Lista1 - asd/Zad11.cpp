
int Zad_11(int n)
{
	n /= 2;
	n -= 2;
	//ALGORYTM MACIEJ SYSLO - 7.6
	bool * primary_1 = new bool[n] ;
	primary_1[0] = false;

	
	for (int k= 1; k <= n; k++)
	{
		primary_1[k] = true;
		
	}
	int i = 1;
	int p = 3;
	int q = 4;
	while (q <= n)
	{
		if (primary_1[i] != false) 
		{
			int j = q;
			while (j <= n)
			{
				primary_1[j] = false;
				j = j + p;
			}
		}
		i = i + 2;
		p = p + 2;
		q = q + 2 * (p - 1);
	}
	int h = 0;
	
	for (int k = n; k > 0; k--)
	{
		
		if (primary_1[k] == true)
		{
			
		 h = k*2+1;
		
		k = 0;
		}
	}

	bool * primary = new bool[h];
	for (int l = 1; l <= h; l++)
	{
		if (primary_1[l] == true)
		{
			primary[l * 2 + 1] = true;
		}
	}
	primary[2] = true;
	 for (int j = 0; j <= h; j++)
	{
		
		if(primary[j] == true)
		{
			cout << j << " " << primary[j] << endl;
		}
	
	}
	return 0;
}