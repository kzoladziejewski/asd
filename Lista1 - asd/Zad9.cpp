int Zad_9()
{
fstream plik;
string nazwa_pliku = "d.txt";
//cin >> nazwa_pliku;
plik.open(nazwa_pliku);
char c;
char ascii[3] = { 'a', 'f', '%' };
int number_ascii[256];
for (int i = 0; i < 256; i++)
{
	number_ascii[i] = 0;
}

while (plik.get(c)) {
	number_ascii[int(c) + 128] += 1;
}
cout << "Taki znaki wystapiły tyle razy:";
for (int i = 0; i < 256; i++)
{
	cout << "Znak: " << char(i - 128) << " wystapil:" << number_ascii[i] <<endl;
}

return 0;
}