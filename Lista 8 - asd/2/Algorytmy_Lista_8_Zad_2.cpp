#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>

#define log(x) (std::cout<< x << std::endl)
#define MAXINT 2147483647
using namespace std;
//struktura miast
struct City
{
	// KLASA DO LATWIJSZEGO UPORZDKOWANIA WIERZCHOLKOW I DO OBLICZENIA ODLEGLOSCI
	int x, y;
	//kostruktor struktury,
	City(double x, double y) : x(x), y(y) {}
	//metoda struktury sluzaca do wyliczania odleglosci
	double distance(City const& other)
	{
		return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
	}
	//wypisywanie kordynatow
	void wypisz() {
		log(x << ", " << y );
	}
};



struct EdgeTo
{
	// KLASA KRAWEDZI POMIEDZY MIASTAMI

	int v;// liczba sasiadow danego wierzcholka
	double d; // dystans/waga danej krawedzi
	//konstruktor struktury
	EdgeTo(int v0, double d0) :v(v0), d(d0) {}

};


//stukrura ktora tworzy mi de facto graf
struct Graf
{
	// GLOWNA KLASA WYLICZENIOWA
	//zbior wszystkich werzcholkow, ich sasiadow i wag
	std::vector<std::vector<EdgeTo>> adj; // wektor trzymajacy wszystkie krawedzie

	std::vector<int> sciezka_Hamiltona; //ta sciezka ktora w miare dziala i jest obecnie najkrotsza
	std::vector<int> pomocnicza_sciezka_Hamiltona;  //tutaj bede trzymal cala sciezke hamiltona jaka wyliczam
	std::vector<bool> odwiedzone; //wektor ktory pilnuje czy dany wierzcholek zostl odwiedzony czy nie
	double dh, d; // zmienna pomocniczna
	bool **A;                         // Macierz s�siedztwa
	double **W;                          // Macierz wag kraw�dzi
	int sptr;						  // biezacy wierzcholek sciezki
	int shptr;						  // biezacy wierzcholek pomocniczej sciezki
	int v0;
	//KONSTRUKTOR GRAFU - 
	Graf(int n) : adj(n), sciezka_Hamiltona(n, 0), pomocnicza_sciezka_Hamiltona(n, 0), odwiedzone(n, false)
	{
		d = MAXINT;
		dh = 0;
		v0 = 0;
		A = new bool*[n]; //tablicna dynamiczna 
		W = new double*[n];

		for (auto i = 0; i < n; i++)
		{//tworze 2d tablice dynamiczna
			A[i] = new bool[n];
			W[i] = new double[n];
			for (int j = 0; j < n; j++)
			{
				A[i][j] = false;
				W[i][j] = 0;
			}

		}
		sptr = 0;
		shptr = 0;

	}

	// konstruktor kopiujacy
	Graf(const Graf& other) : dh(other.dh), d(other.d), sptr(other.sptr), shptr(other.shptr), v0(other.v0)
	{
		sciezka_Hamiltona = other.sciezka_Hamiltona;
		pomocnicza_sciezka_Hamiltona = other.pomocnicza_sciezka_Hamiltona;
		odwiedzone = other.odwiedzone;
		adj = other.adj;
		A = new bool*[adj.size()];
		W = new double*[adj.size()];


		for (auto i = 0; i < adj.size(); i++)
		{
			A[i] = new bool[adj.size()];
			W[i] = new double[adj.size()];
		}

		for (auto i = 0; i < adj.size(); i++)
		{
			for (auto j = 0; j < adj.size(); j++) {
				A[i][j] = other.A[i][j];
				W[i][j] = other.W[i][j];
			}
		}



	}
	//dodaje do wektora krawedzi kolejna krawedz
	void edge(int i, int j, double w = 1)
	{
		adj[i].push_back(EdgeTo(j, w));
	}

	//wypisuje mi macierz sasiedztwa - krawedzie i wagi
	void show(bool with_weights = true)
	{
		int i = 0;
		for (auto u : adj)
		{
			std::cout << i++ << ":";
			for (auto e : u)
			{
				std::cout << " " << e.v;
				if (with_weights)
					std::cout << "(" << e.d << ")";
			}
			std::cout << std::endl;
		}
	}
	// problem komiwojazera - szukanie cyklu Hamiltona

	void TSP(int v)
	{
		int u;

		pomocnicza_sciezka_Hamiltona[shptr++] = v;                // zapami�tujemy na stosie bie��cy wierzcho�ek

		if (shptr < adj.size())                   // je�li brak �cie�ki Hamiltona, to jej szukamy
		{
			odwiedzone[v] = true;            // Oznaczamy bie��cy wierzcho�ek jako odwiedzony
			for (u = 0; u < adj.size(); u++)        // Przegl�damy s�siad�w wierzcho�ka v
				if (A[v][u] && !odwiedzone[u])  // Szukamy nieodwiedzonego jeszcze s�siada
				{
					dh += W[v][u];            // Dodajemy wag� kraw�dzi v-u do sumy
					TSP(u);                   // Rekurencyjnie wywo�ujemy szukanie cyklu Hamiltona
					dh -= W[v][u];            // Usuwamy wag� kraw�dzi z sumy
				}
			odwiedzone[v] = false;           // Zwalniamy bie��cy wierzcho�ek
		}
		else if (A[v0][v])               // Je�li znaleziona �cie�ka jest cyklem Hamiltona
		{
			dh += W[v][v0];               // to sprawdzamy, czy ma najmniejsz� sum� wag
			if (dh < d)                    // Je�li tak,
			{
				d = dh;                     // To zapami�tujemy t� sum�
				for (u = 0; u < shptr; u++)  // oraz kopiujemy stos Sh do S
					sciezka_Hamiltona[u] = pomocnicza_sciezka_Hamiltona[u];
				sptr = shptr;
			}
			dh -= W[v][v0];               // Usuwamy wag� kraw�dzi v-v0 z sumy
		}
		shptr--;                        // Usuwamy bie��cy wierzcho�ek ze �cie�ki
	}



	// koniec funkcji odpowiedzialnych za problem komiwojazera


	void wypiszWagi() {

//nie ma znaczenia dla naszego zycia, bylo bo cos robilo  - prawdilowy zapis do macierzy
		for (int i = 0; i < adj.size(); i++) {
			for (int j = 0; j < adj.size(); j++)
			{
				std::cout << W[i][j] << " " << "ael";
			}
			log("");
		}

	}


	~Graf()
	{
		//czyszczenie pamieci z wszelkiego smiecia
		for (auto i = 0; i < adj.size(); i++)
		{
			delete[] A[i];
			delete[] W[i];
		}
		delete[] A;
		delete[] W;

	}


};

/////////////////////////////////	ZAPISANIE WYNIKU DO PLIKU /////////////////////	

void write_to_file(Graf & graf)
{

	std::ofstream plik("trasa.txt", std::ios::out);
	if (plik.good())
	{
		log("Zapisuje do pliku...");

		graf.TSP(graf.v0); // wywolanie funkcji obliczajacej problem komiwojazera
		if (graf.sptr) /// jesli sciezka zostala znaleziona ?
		{
			log("Trasa");
			plik << graf.adj.size() << " " << graf.d << "\n"; // ilosc miast i dlugosc sciezki
			for (int i = 0; i < graf.sciezka_Hamiltona.size(); i++)
			{
				log(graf.sciezka_Hamiltona[i] << " ");
				plik << graf.sciezka_Hamiltona[i] << " "; // wypisanie po kolei krokow sciezki
			}
			log(graf.v0);
			plik << graf.v0; // wypisanie ostatniego kroku sciezki
			log("dlugosc = " << graf.d);
		}
		else { log("NO HAMILTONIAN CYCLE"); plik << "NO HAMILTONIAN CYCLE"; }
		plik.close();
	}
	else
		std::cerr << "file error" << std::endl;

}

//////////////////////////	WCZYTYWANIE MIAST ///////////////////////////////

Graf read_from_file()
{

	std::ifstream plik("miasta.txt");
	if (plik.good())
	{
		log("Czytam z pliku...");
		int n, number;
		std::vector<City> miasta;
		std::vector<double> wspolrzedne;
		int krok = 0;
		while (plik >> number) {
			if (krok == 0) {
				n = number;   // w pierwszym kroku czytamy z pierwszej linii pilku ile miast ma byc
				miasta.reserve(n); // rezerwujemy w wektorze miejsce na miasta
			}
			else {
				wspolrzedne.push_back(number);  // w pozostalych krokach dodajemy wspolrzedne do wektora wspolrzednych
			}
			krok++;
		}
		for (auto i = 0; i < wspolrzedne.size(); i += 2)
		{
			miasta.emplace_back(City(wspolrzedne[i], wspolrzedne[i + 1]));
		}

		Graf graf(n); //tu tworze tak naprawde ten graf

		for (int i = 0; i < miasta.size(); i++) {

			for (int j = 0; j < miasta.size(); j++) {

				if (i != j) {
					graf.edge(i, j, miasta[i].distance(miasta[j]));//wypelniam wektory grafu odpowiednimi krawedziai
					graf.A[i][j] = true;
					graf.W[i][j] = miasta[i].distance(miasta[j]);
				}

			}
		}


		plik.close();
		return graf; //zwracamy gotowy graf problemu

	}
	else {
		std::cerr << "file error" << std::endl;
		Graf graf(0);
		return graf;
	}
}



int main()
{

	//tworze nowa instalcje klasy, tworze nowy graf
	Graf komiwojazer(read_from_file());

	log("Wynikowe polaczenia Grafu: ");
	komiwojazer.show(true); // wyswietla wszystkie krawedzie i wierzcholki

	write_to_file(komiwojazer); // zapisuje wynik

	std::cin.get();
	return 0;
}