void Zad_4(int n, int k)
{
	int  *arr = new int[n];
	for (int i = 0; i <= n; i++)
	{
		arr[i] = i;
		cout << arr[i] << " " ;
	}
	cout << endl;
	
	int hot;
	for (int u = 0; u < k; u++) {
	int key = arr[n];
		for (int j = n; j >= 0; j--)
		{
			if (j == 0)
			{
				arr[j] = key;
			}
			if (j > 0) {
				arr[j] = arr[j - 1];
			}

		}
	}

	cout << endl;
	for (int i = 0; i <= n; i++)
	{
	
		cout << arr[i] << " ";
	}

}