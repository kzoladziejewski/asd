#include "stdafx.h"
#include "Wielomiany.h"


Wielomiany::Wielomiany()
{
}
void Wielomiany::zapis(const char* nazwa_pliku, vector<int> const& w)
{
	ofstream plik(nazwa_pliku);
	for (int i = 0; i < w.size(); i++)
	{
		plik << to_string(w[i]);
	}
}

Wielomiany::~Wielomiany()
{
}
