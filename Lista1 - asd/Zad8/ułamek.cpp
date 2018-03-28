#include "stdafx.h"
#include "ułamek.h"


int ułamek::pobierz_licznik()
{
	return licznik;
}
int ułamek::pobierz_mianownik()
{
	return mianownik;
}
void ułamek::set_licznik(int a) {
	licznik = a;
}
void ułamek::set_mianownik(int a) {
	if (a == 0)
	{
		throw ExceptionZero("NIE ZERO!");
	}
	mianownik = a;
}
void ułamek::skracanie()
{
	bool skracam = true;

	while (skracam == true) {
	
		//TUTAJ POWINIENEM UZYC ALGORYTMU Z SITA ERASTOTENESA NA LICZBY PIERWSZE.
		//STWORZYC JAKAS TABLICE CZY COS.
		if (licznik % 2 == 0 && mianownik % 2 == 0)
		{
			licznik /= 2;
			mianownik /= 2;
		}
		if (licznik % 3 == 0 && mianownik % 3 == 0)
		{
			licznik /= 3;
			mianownik /= 3;
		}
		if (licznik % 5 == 0 && mianownik % 5 == 0)
		{
			licznik /= 3;
			mianownik /= 3;
		}
		if (licznik % 5 == 0 && mianownik % 5== 0)
		{
			licznik /= 5;
			mianownik /= 5;
		}
		else {
			skracam = false;
		}
	}
}
void ułamek::nwd(ułamek & drugi)
{
	int a = mianownik;
	int b = drugi.pobierz_mianownik();
	if (a != b)
	{
		mianownik *= b;
		licznik *= b;
		drugi.set_licznik(drugi.pobierz_licznik()*a);
		drugi.set_mianownik(drugi.pobierz_mianownik()*a);
	}
}
ułamek::ułamek()
{
	licznik = 1;
	mianownik = 1;

}

ułamek::ułamek(int i, int n)
{
	//if (mianownik == 0)
	//	throw ExceptionZero("NIE ZERO!");
	this->licznik = i;
	this->mianownik = n;
	cout << licznik << "NO NIE WIEM11111111" << mianownik << " " << i << n << endl;
	skracanie();
}


ułamek::~ułamek()
{
}
