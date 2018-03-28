#include <stdio.h>
#include <iostream>

using namespace std;

struct lnode
{
    int key;
    lnode *next;
    lnode(int n = 0, lnode *l = NULL) : key(n), next(l) {};
};

int getLength(lnode* L)
{
    int length = 0;

    while (L)
    {
        ++length;
        L = L->next;
    }

    return length;
}

lnode* merge(lnode* L1, lnode* L2)
{
	lnode *temp;
  	lnode *L = new lnode();
  	temp = L;

  	while (L1 && L2)
  	{
    	if (L1->key > L2->key)
    	{
      		temp->next = L2;
      		L2 = L2->next;
    	}
    	else {
			temp->next = L1;
     	 	L1 = L1->next;
    	}
    	temp = temp->next;
  	}

  	while (L1)
  	{
    	temp->next = L1;
    	L1 = L1->next;
    	temp = temp->next;
  	}

  	while (L2)
  	{
    	temp->next = L2;
    	L2 = L2->next;
    	temp = temp->next;
  	}

  	temp = L;

  	if (temp)
  	{
    	L = temp->next;
    	delete temp;
  	}

  	return L;
}

void mergeSort(lnode*& L)
{
    //zmienne pomocnicze do forów, i sie przyda pozniej
    int i, j;
    //biore dlugosc listy
    int length = getLength(L);
    //by nie operowal na L, tworze sobie kolejna liste
    lnode* sorted[length + 1];
    //przepisuje sobie drzewko 
    for (i = 0; i < length; ++i)
    {
        //ta pozycja w sroted = bierze aktualny l
        sorted[i] = L;
        //lece na nastpeny L
        L = L->next;
        //tworze nulla dla astepnego, puste miejsce 
        sorted[i]->next = NULL;
    }
    //potrzebny do srodka
    int mid = length;
    //ostatni element listy ma miec nulla w next
    sorted[i] = NULL;
    //dopoki m jest wieksze od 1
    while (mid > 1)
    {
        //petelka ktora mi sortuje i wstawia do listy uporzadkowany elemencik, 
        for(i = j = 0; i < mid; i += 2, ++j)
            sorted[j] = merge(sorted[i], sorted[i+1]);

        mid = (mid + 1) / 2;
    }
//start listy
L = sorted[0];
}

void print(lnode *L)
{
    while (L != NULL)
    {
        cout << L->key << "  ";
        L = L->next;
    }
    cout << endl;
}

int main()
{
    lnode *l = NULL;

    l = new lnode(7, l);
	l = new lnode(5, l);
    l = new lnode(2, l);
	l = new lnode(3, l);
    l = new lnode(2, l);
	l = new lnode(1, l);
	l = new lnode(9, l);

    print(l);
    mergeSort(l);
    print(l);

    return 0;
}
