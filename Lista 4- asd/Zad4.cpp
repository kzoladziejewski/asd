int partition(int a, double t[], int b)
{ 
	//przyjmuje sobie zmienna od ktorej lece, w normalnym partition jest to x, tutaj a
	int e = t[a];
	//dopoki a jest mniejsze od b, pilnuje by, tak jak w przypadku x gdy obie liczby sie wymienia nastapil koniec
	while (a < b)
	{
	
		//dopoki a jest mniejsze od b i [t]b jest wieksze od wartosci, zmniejsz b 
		while ((a < b) && (t[b]>=e))  b--;
		//to samo ale na odwrót
		while ((a < b) && (t[a] < e)) a++;
		//niepotrzebne w sumie ale lepiej miec niz nie miec.
		if (a < b)
			
		{
			//zamiana miejsc
			double y = t[a];
			t[a] = t[b];
			t[b] = y;
		}
		//zwracam moje a w podmianie
		return a;
	}
}

int kty(double t[], int n)
{
	//PLUS I MINUS 1 JEST DLATEGO ZE INDEKSOWANIE JEST OD 0, NIE OD 1
	int a,k;
	cout << "Podaj ktory element ciagu chcesz znalezc";
	cin >> a;
	//indeks w tablicy
	int i = 0;
	//ustalam sobie przedostatni element
	int j = n - 1;
	//przypisuje do rozmiaru tablicy na ile mam ja dzielic
	n = a;
	//dopoki i nie będzie mialo tej samej wartosci co j
	while (i != j)
	{
		//rozpoczynam dzielenie tablicy na dwa elementy - i i j
		 k = partition(i, t, j);
		//znaleziona pozycja jest zmniejszona o i plus 1
		k = k - i + 1;

		if (k >= a)
		{
			//to tak naprawde przywlaszcza mi j do i tak by bylo, stopuje petelke
			j = i + k - 1;

		}
		if (k < a)
		{
			//zmniejszam a o to co znalazlem o 1
			a -= k;
			//zwiekszam indeks o 1 tak naprawde, zawsze 
			i += k;
		}
	}
	cout << "element n: " << n << "wynosi" << t[i] << endl;
	return 0;
}
