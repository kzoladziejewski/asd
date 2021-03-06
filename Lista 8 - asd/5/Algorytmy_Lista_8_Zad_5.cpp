/*
Problek konika (skoczka) szachowego
www.algorytm.org
Adam Mika (c) 2008

Algorytm podaje pierwsze dopuszczalne rozwi�zanie problemu dla kolejnych punkt�w
startowych pod warunkiem, �e takie rozwi�zanie istnieje.
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

bool ruch(int** tab, const int& N, int wariant, int x, int y, int& nx, int& ny)
{
	//switch, wybierajacy mozliwosc ruchu, przesuwa skoczka o dana pozycje jesli istnieje taka mozliwosc
	switch (wariant) {
	case 1:
		nx = x + 1;
		ny = y - 2;
		break;
	case 2:
		nx = x + 2;
		ny = y - 1;
		break;
	case 3:
		nx = x + 2;
		ny = y + 1;
		break;
	case 4:
		nx = x + 1;
		ny = y + 2;
		break;
	case 5:
		nx = x - 1;
		ny = y + 2;
		break;
	case 6:
		nx = x - 2;
		ny = y + 1;
		break;
	case 7:
		nx = x - 2;
		ny = y - 1;
		break;
	case 8:
		nx = x - 1;
		ny = y - 2;
		break;
	}

//klamalem, po prostu przesuwa skoczka a potem sprawdza czy nowy x ktory jest na chwile obecna podpisany nx
	//czy czasem ten nx nie jest rowny albo mniejszy od zera
	//oraz czy czasem nie przesadziło w wielkoscia
	//N moze byc n*n ale tak naprawdę możliwych ruchów jest N-1, iteracja od 0
	//to samo z y
	//i na samym koncu sprawdza czy to miejsce jest puste
	if (0 <= nx && nx < N && 0 <= ny && ny < N && tab[nx][ny] == 0)

	{//jeśli cały ten duzy warunek zostal spelniony to zwraca mi true!
		return true;
	}
	//a jeśli uzna że nie to zwraca false
	return false;
}

bool skoczek(int** tab, const int& n, int x, int y, int ktory)
{
	//tworze zmienne ktore sa potrzebne do ruchu i
	int nx, ny, w;
	//umieszczam skoczka na tej tablicy
	tab[x][y] = ktory;
	//leci literacja ktora sprawdza czy ilosc ruchow skoczka jest taka ile wynosi rozmiar tablicy
	//oznacza to wtedy że przeszedł on przez całe piekło
	if (ktory == n * n)
	{
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
				cout << tab[j][i] << " ";
			cout << endl;
		}
		return 1;
	}
	//no jesli nie rowna sie to znaczy ze trzeba go przeprowadzic
	else
	{
		//skoczek ma 8 mozliwosci ruchu tak naprawde, zawsze:
		//
		for (w = 1; w < 9; w++)
			//sprawdzam czy istnieje możliwośc ruchu w danym kierunku;
		{		if (ruch(tab, n, w, x, y, nx, ny) == true)
				//o jeśli istnieje to wykonuje ruch skoczkiem, zwiekszajac jego ilosc ruchow o 1
				//jak mi sie odpali tam ten if (ktoru=n*n) to wtedy zwraca mi true i jest koniec programu
			{
			if (skoczek(tab, n, nx, ny, ktory + 1) == true)
				//koniec programu
			{
				return true;
			}
			}
	}
		tab[x][y] = 0;
	}

	return false;
}

void clearTab(int** tab, const int& n)
{
	//czyszczenie
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			tab[i][j] = 0;
}

int main()
{
	int max;
	cin >> max;
	//tylko jeden sposob na zrobienie dynamicznej tablicy 2d
	//polega taknaprawde na robieniu jeden tablicy tablic
	int** tab = new int*[max];
	for (int i = 0; i<max; i++)
		tab[i] = new int[max];

	//od każdej pozycji jest badany skoczek, od 0,0 do max-1,max-1
	for (int i = 0; i<max; i++)
		for (int j = 0; j<max; j++)
		{
			clearTab(tab, max); // czyszcze tablice by nie miec problemow
			cout << "\n(i,j)= " << i << ", " << j << "\n"; //wypisuje z ktorej pozycji startuje
			//jak sie uda zrobic skoczka to wypisze mi jego ruchu, jesli nie uda sie bo przejdzie dalej
			skoczek(tab, max, i, j, 1); //przekazuje tablice, jej rozmiar, pozycje skoczka i liczbe ruchow juz wykonanych
		}

	cin >> max;
	return 0;
}
