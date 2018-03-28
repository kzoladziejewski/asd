#pragma once
#include <exception>
#include <iostream>
#include <string>
using namespace std;
class ExceptionZero : public runtime_error
{
public:
	ExceptionZero(const char *error) : runtime_error(error) {};
};

class ułamek
{
private:
	int mianownik = 1;
	int licznik = 1;
public:
	ułamek(int licznik, int mianownik = 1 );
	~ułamek();
	ułamek();
	void skracanie();
	void set_mianownik(int a);
	void set_licznik(int a);
	void nwd(ułamek & drugi);
	int pobierz_licznik();
	int pobierz_mianownik();
	friend ostream & operator<< (ostream &wyjscie, ułamek &u)
	{
		return wyjscie << u.pobierz_licznik() << "/" << u.pobierz_mianownik() << endl;
	}
	friend istream & operator>> (istream &wejscie, ułamek &u)
	{
		string ulamek;
		wejscie >> ulamek;
		int position = ulamek.find('/');
		int end = ulamek.length() - 1;
		string ulamek2 = ulamek;
		string licz = ulamek2.erase(position, end);
		position++;
		
		string mianow = ulamek.erase(0, position);

		u.set_licznik(atoi(licz.c_str()));
	
		u.set_mianownik(atoi(mianow.c_str()));
		u.skracanie();

		return wejscie;
	}
	friend ułamek operator* (ułamek &jeden, ułamek &dwa)
	{
		ułamek wynik;
		wynik.set_licznik(jeden.pobierz_licznik() * dwa.pobierz_licznik());
		wynik.set_mianownik(jeden.pobierz_mianownik() * dwa.pobierz_mianownik());
		wynik.skracanie();
		return wynik;
	}

	friend ułamek operator/ (ułamek &jeden, ułamek &dwa) {
		ułamek wynik;
		wynik.set_licznik(jeden.pobierz_licznik() * dwa.pobierz_mianownik());
		wynik.set_mianownik(jeden.pobierz_mianownik() * dwa.pobierz_licznik());
		wynik.skracanie();
		return wynik;
	}
	friend ułamek operator+ (ułamek &jeden, ułamek &dwa) {
		ułamek wynik;
		jeden.nwd(dwa);
		wynik.set_licznik(jeden.pobierz_licznik() + dwa.pobierz_mianownik());
		wynik.set_mianownik(jeden.pobierz_mianownik() + dwa.pobierz_licznik());
		wynik.skracanie();
		return wynik;
	}
	friend ułamek operator- (ułamek &jeden, ułamek &dwa) {
		ułamek wynik;
		jeden.nwd(dwa);
		wynik.set_licznik(jeden.pobierz_licznik() - dwa.pobierz_mianownik());
		wynik.set_mianownik(jeden.pobierz_mianownik() - dwa.pobierz_licznik());
		wynik.skracanie();
		return wynik;
	}

};

