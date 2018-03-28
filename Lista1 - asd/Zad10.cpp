#include "stdafx.h"
#include <iostream>



template <typename T> 
class Stos {
private:
	T * tab;
	size_t size;
public:
	Stos() {
		size = 0;
		tab = nullptr;
	}
	Stos(T element)
	{
		size = 1;
		tab = new T[size];
		tab[0] = element;
	}
	~Stos() {
		delete[] tab;
	}
	void push(T element) {
		
		size++;
		T * copy_tab = new T[size];
		for (auto i = 0; i < size - 1; i++) {
			copy_tab[i] = tab[i];
		}
		copy_tab[size - 1] = element;
		delete[] tab;
		tab = new T[size];
		for (auto i = 0; i < size; i++) {
			tab[i] = copy_tab[i];
		}
		
		delete[] copy_tab;

		
	}
	//zdejmowanie powinno zwracac element T , natomiast dla wygody prezentowania dzialania zdecydowalem sie na void
	void pop_back() {

		size--;
		T * copy_tab = new T[size];
		for (auto i = 0; i < size; i++) {
			copy_tab[i] = tab[i];
		}
		
		delete[] tab;
		tab = new T[size];
		for (auto i = 0; i < size; i++) {
			tab[i] = copy_tab[i];
		}

		delete[] copy_tab;


	}
	bool is_empty() {
		if (size == 0 || tab == nullptr) {
			return true;
		}
		return false;
	}

	void wypisz_stos() {
		std::cout << "STOS"<<std::endl;
		for (auto i = size-1; i < -1; i--)
		{
			std::cout << tab[i] << std::endl;
		}
		std::cout << std::endl;
	}

};

template <typename T>
class Kolejka {
protected:

	T tab[100];
	size_t size;
	
public:
	Kolejka() {
		size = 0;
		
	}
	Kolejka(T element)
	{
		size = 1;
		tab[size - 1] = element;
	}
	virtual ~Kolejka() {
		
	}
	virtual void enqueue(T element) {
		if (size < 100) {
			size++;
			tab[size - 1] = element;
		}
		else {
			std::cerr << "Brak miejsca w kolejce" << std::endl;
		}
	}
	//zdejmowanie powinno zwracac element T , natomiast dla wygody prezentowania dzialania zdecydowalem sie na void
	virtual void dequeue() {

		if (!isEmpty()) {

			size--;
			for (auto i = 0; i < size; i++)
			{
				tab[i] = tab[i + 1];
			}
		}

	}
	virtual void wypisz() {
		std::cout << "KOLEJKA" << std::endl;
		for (auto i = 0; i < size; i++)
		{
			std::cout << tab[i] << std::endl;
		}
		std::cout << std::endl;
	}
	bool isEmpty() {
		if (size == 0) return true;
		return false;
	}

};

template <typename T>
class Kolejka_Priorytetowa
	:public Kolejka<T>
{
	int priorytety[100];

public:
	Kolejka_Priorytetowa() {
		size = 0;
		
	}
	Kolejka_Priorytetowa(T element, int priorytet)
	{
		size = 1;
		tab[size - 1] = element;
		priorytety[size - 1] = priorytet;
	}
	~Kolejka_Priorytetowa() {
		
	}
	void wypisz() override {
		std::cout << "KOLEJKA PRIORYTETOWA" << std::endl;
		for (auto i = 0; i < size; i++)
		{
			std::cout << tab[i] << std::endl;
		}
		std::cout << std::endl;
	}

	void enqueue(T element, int priorytet) {
		if (size < 100) {
			size++;
			tab[size - 1] = element;
			priorytety[size - 1] = priorytet;
		}
		else {
			std::cerr << "Brak miejsca w kolejce" << std::endl;
		}
	}

	void dequeue() override {
		int max = 0;
		int max_index = 0;
		for (auto i = 0; i < size; i++) {
			if (priorytety[i] > max) {
				max = priorytety[i];
				max_index = i;
			}
		}
		size--;
		for (auto i = 0; i < size; i++) {
			if (i >= max_index) {
				tab[i] = tab[i + 1];
				priorytety[i] = priorytety[i + 1];
			}
		}

	}
	
	
};

int main()
{
	Stos<int> stos;
	stos.push(5);
	stos.push(10);
	stos.push(2);
	stos.wypisz_stos();
	stos.pop_back();
	stos.wypisz_stos();
	stos.push(100);
	stos.wypisz_stos();
	
	Kolejka<int> kolejka(3);
	kolejka.enqueue(34);
	kolejka.enqueue(12);
	kolejka.wypisz();
	kolejka.dequeue();
	kolejka.wypisz();
	kolejka.enqueue(-13);
	kolejka.wypisz();
	kolejka.dequeue();
	kolejka.wypisz();
	

	Kolejka_Priorytetowa<int> priory(80 , 1);
	priory.enqueue(12, 4);
	priory.enqueue(3, 8);
	priory.enqueue(8, 2);
	priory.enqueue(5, 3);
	priory.wypisz();
	priory.dequeue();
	priory.wypisz();
	priory.dequeue();
	priory.wypisz();
	std::cin.get();
	return 0;

}




