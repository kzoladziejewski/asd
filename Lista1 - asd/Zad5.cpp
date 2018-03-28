#include "stdafx.h"
#include <iostream>

struct lnode {
	int key;
	lnode* next;

	lnode(int value, lnode* l = nullptr) {
		key = value;
		next = l;
	}
};

int nty(int n, lnode * l) {
	
	int _n = 1;
	while (l != nullptr) {
		if (_n == n) {
			return l->key;
		}
		else {
			_n++;
			l = l->next;
		}
	}
	return 0;
}


int main(void)
{
	
	lnode third(3);
	lnode second(2, &third);
	lnode first(1, &second);
	
	std::cout << nty(1, &first) << std::endl;
	std::cout << nty(2, &first) << std::endl;
	std::cout << nty(3, &first) << std::endl;
	//wyjscie poza zakres
	std::cout << nty(4, &first) << std::endl;

	std::cin.get();
	return 0;
}




