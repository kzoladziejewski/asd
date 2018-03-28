#include <stdio.h>
#include <iostream>
 
using namespace std;

struct lnode
{
    int key;
    lnode *next;
    lnode(int n=0, lnode *l = NULL) : key(n), next(l) {};
};

void print(lnode *L)
{
    while (L != NULL)
    {
        cout << L->key << "  ";
        L = L->next;
    }
    cout << endl;
}

void insertion_sort(lnode *&L)
{

    //sprawdza czy L istnieje i nie jest 1 argumentowa
    //jeden argument jest uporzadkowana lista
    if (L && L->next)
    {
        //tworzr sobie pusta liste pomocnicza
        lnode* sortedL = NULL;
        //by nie modyfikować L w czasie rzeczywistym bo dzieje sie pieklo
        lnode* unsortedL = L;
        //dopoki nieposortowana nie dotrze do swojego konca
        while (unsortedL)
        {
            //dodatkowa zmienna, pobiera m iaktualny unsorted
            lnode* value = unsortedL;
            //przeskakuje na nastepna wartosc
            unsortedL = unsortedL->next;
            //jesli moja lista jest pusta albo wartosc nieposortowanej jest mniejsza od klucza z posortowanej
            if (!sortedL || value->key <= sortedL->key) 
            {
                //ustalam nieposrtowany klucz na ten klucz
                value->next = sortedL;
                //zapisuje sobie miejsce w liscie
                sortedL = value;
            } else
            {
                //kolejna pomocniczna zmienna, dla pamieci porownywania liczb, tutaj rosnie wielkosc listy
                lnode* curSorted = sortedL;
                //dopoki nie dojdzie do konca
                while (curSorted)
                {
                    //jesli nastepny klucz obecnej zmiennej nie jest null albo liczba z value jest mniejsza od nastepnego currenta
                    if (!curSorted->next || value->key < curSorted->next->key)
                    {
                        //przypisanie do nastepnego value obecnego sorta
                        value->next = curSorted->next;
                        //prawie to samo, zamiana miejsc
                        curSorted->next = value;
                       //by mi sie nie zapetlilo 
                        break;
                    }
                    //wklepujemy curenta na nastepne miejsce
                    curSorted = curSorted->next;
                }
            }
        }
        //nadpisanie listy nowa
        L = sortedL;
    }
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
    insertion_sort(l);
    print(l);

    return 0;
}
