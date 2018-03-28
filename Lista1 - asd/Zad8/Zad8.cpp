void Zad_8()
{
	ułamek u1;
	ułamek u2;
	cout << "Wprowadz dwa ulamki, oddzielone enterem w formie x/y " << endl;
	cin >> u1;
	cin >> u2;
	cout << u1 << "  " << u2 << endl;;
	char wybor = ' ';
	cout << "Mnozymu (*), dzielimu (/), dodajemy (+) czy odejmujemu (-)?";
		cin >> wybor;
		if (wybor == '*')
		{
			cout << u1*u2 << endl;
		}
		if (wybor == '+')
		{
			cout << u1+u2 << endl;
		}
		if (wybor == '/')
		{
			cout << u1/u2 << endl;
		}
		if (wybor == '-')
		{
			cout << u1-u2 << endl;
		}
		
}