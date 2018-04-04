	void position_sort(unsigned z1[], unsigned z2[], unsigned m)
{
	unsigned L[2], i;

	L[0] = L[1] = 0;
	for (i = 1; i <= N; i++) L[(z1[i] & m) > 0]++;
	L[1] += L[0];
	for (i = N; i >= 1; i--) z2[L[(z1[i] & m) > 0]--] = z1[i];


}
    
    int main()
    {unsigned d[N + 1], b[N + 1], i, m;
	m = 1;
	srand((unsigned)time(NULL));
	for (i = 1; i <= N; i++)
	{
		d[i] = rand() % (MAXEL + 1);
		cout << " " << d[i];
	}
	while (m <= MAXEL)
	{
		position_sort(d, b, m); m <<= 1;
		position_sort(b, d, m); m <<= 1;
	}

	// Wyświetlamy wyniki
	cout << "\nPo sortowaniu:\n\n";
	for (i = 1; i <= N; i++)
	{
		cout << " " << d[i];
		cout << endl;
	}
    }
	