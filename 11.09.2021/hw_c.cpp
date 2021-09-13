#include <iostream>
#include <vector>

int main()
{
	std::vector < int > vect = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 14 };

	unsigned int l = 0;
	unsigned int r = std::size(vect) - 1;
	unsigned int m;
	int value;

	std::cin >> value;

	while (l != r)
	{
		m = (l + r) / 2 + 1; // == ceil
		
		if (vect[m] > value)
		{
			r = m - 1;
		}

		else
		{
			l = m;
		}
	}

	if (vect[l] == value)
	{
		std::cout << "Found at position: " << l << '\n';
	}

	else
	{
		std::cout << "Search unsuccessful." << '\n';
	}
	
	system("pause");
	return 0;
}