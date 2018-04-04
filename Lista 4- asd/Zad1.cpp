#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;
void counting_sort(int t[], int n, int c)
{
	int licznik[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int * sorted_array = new int[n];
	int dzielnik = pow(10,c);
	int pozycja = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < n; j++)
		{
		if ((t[j] / dzielnik) == i)
			{
				licznik[i] = licznik[i] + 1;
				sorted_array[pozycja] = t[j];
				pozycja++;
			}
		}
	}
	for (int h = 0; h < n; h++)
	{
		t[h] = sorted_array[h];
		cout << sorted_array[h] << endl;
	}
	for (int k = 0; k < 10; k++)
	{
		cout << "Liczba:" << k << "wystepuje: " <<  t[k] << endl;
	}

}

int main()
{
	//int t[21] = { 4,5,4,4,2,8,5,1,7,3,0,8,5,2,6,1,7,3,5,1,2 };
	//int t[21] = { 43,53,43,34,23,83,53,13,73,33,03,83,53,23,63,13,74,32,54,11,22 };
	int t[21] = { 413,503,493,384,273,863,311,143,733,323,013,803,53,283,673,163,754,342,534,121,212 };
	int n = 21;
	int c =2;
	counting_sort(t, n, c);
}