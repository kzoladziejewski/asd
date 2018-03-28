#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Wielomiany
{
public:
	Wielomiany();
	~Wielomiany();
	void zapis(const char* name_of_file, vector<int> const& w);
	vector<int> pobierz(const char * nazwa_pliku)
	{
		{
			vector<int> wierzcho³ki;
			fstream plik(nazwa_pliku, ios::in);
			if (plik.good())
			{
				cout << "DZIA£A" << endl;
				string buffer;
				while (getline(plik,buffer))
				{

						wierzcho³ki.push_back(atoi(buffer.c_str()));
				}

			}
			return wierzcho³ki;
		}
	}

	vector<int> iloczyn(vector<int> &jeden,vector<int> &dwa)
	{
		vector<int> wynik;
		int wynik_1 = 0;
		for (auto i = 0; i < jeden.size(); i++)
		{
			wynik_1 = 0;
			for (auto j = 0; j < dwa.size(); j++)
			{
				wynik_1 += jeden[i] * dwa[j];
			}
			wynik.push_back(wynik_1);
		}
		return wynik;
	}
	

	
};

