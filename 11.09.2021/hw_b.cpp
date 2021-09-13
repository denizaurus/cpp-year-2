#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector < int > vect = { 9, -2, 83, 34567, 849, -19, 0, -68, 983 };

	for (auto i = 1U; i < std::size(vect); ++i)
	{
		for (int j = i; j > 0; --j)
		{
			if (vect[j-1] > vect[j])
			{
				std::swap(vect[j-1], vect[j]);
			}
		}
	}

	for (auto i = 0U; i < vect.size(); ++i) // вывод отсортированного вектора
	{
		std::cout << vect[i] << ", ";
	}

	system("pause");
	return 0;
}

