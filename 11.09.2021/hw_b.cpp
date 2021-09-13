/* Ðàáîòàåò äî îêîí÷àíèÿ ââîäà (Ctrl+Z) */

#include <iostream>
#include <vector>

int main()
{
	std::vector < int > vect;
	int temp, j, element;

	while (std::cin >> element) // çàïèñü â âåêòîð
	{
		vect.push_back(element);
	}

	for (auto i = 1U; i < vect.size(); ++i) // îïòèìèçèðîâàííàÿ ñîðòèðîâêà âñòàâêàìè
	{
	temp = vect[i];
	j = i - 1;

		while ((j >= 0) && (vect[j] > temp)) // âíóòðåííèé öèêë ñîðòèðîâêè
		{
			vect[j + 1] = vect[j]; 
			--j;
		}

	vect[j + 1] = temp;
	}

	for (auto i = 0U; i < vect.size(); ++i) // âûâîä îòñîðòèðîâàííîãî âåêòîðà
	{
		std::cout << vect[i] << ", ";
	}

	system("pause");
	return 0;
}