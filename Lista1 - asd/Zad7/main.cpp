#include "Wielomiany.h"
using namespace std;
int main()
{
	
	std::vector<int> w1 = pobierz("a.txt");
	std::vector<int> w2 = pobierz("b.txt");
	std::vector<int> w3 = iloczyn(w1, w2);
	zapis_do_pliku("c.txt", w3);
	for (auto const& w : w3)
	{
		cout << w << endl;
	}

	std::cin.get();
	return 0;
}
