double P(int k, int n, double p)
{
	
	double q = (1 - p);
	double  p_q = p / q;
	double skladnik = pow(q, n);
	double suma = 0;
	int i;
	for (i = 0; i <= k; i++)
	{
		suma+=skladnik;
		skladnik =skladnik* p_q * ((n - 1) / (i + 1));
		//sa 3 mnozenia
	}
	return suma;

}