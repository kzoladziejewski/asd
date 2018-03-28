double Zad_3(double a[], int n, double x)
{double wynik = a[n];
while (n)
{
	wynik = wynik*x + a[--n];
}	
return wynik;
}