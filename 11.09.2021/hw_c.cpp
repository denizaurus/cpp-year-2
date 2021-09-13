#include <iostream>
#include <vector>

int main()
{
	std::vector < int > vect = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	int l, r, m, value; // signed int в индексе применяется для избежания ошибок

	std::cin >> value;

	l = 0;
	r = vect.size() - 1;

	while (l <= r)
	{
		m = (l + r) / 2; // для int >= 0 автоматически возвращает floor
		
		if (vect[m] < value)
		{
			l = m + 1;
		}

		else if (vect[m] > value)
		{
			r = m - 1;
		}

		else
		{
			std::cout << "Found at position: " << m << '\n';
			return 0;
		}

	}

	std::cout << "Search unsuccessful." << '\n';
	system("pause");
	return 0;
}