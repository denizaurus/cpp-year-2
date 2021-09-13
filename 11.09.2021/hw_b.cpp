/* Работает до окончания ввода (Ctrl+Z) */

#include <iostream>
#include <vector>

int main()
{
	std::vector < int > vect;
	int temp, j, element;

	while (std::cin >> element) // запись в вектор
	{
		vect.push_back(element);
	}

	for (auto i = 1U; i < vect.size(); ++i) // оптимизированная сортировка вставками
	{
	temp = vect[i];
	j = i - 1;

		while ((j >= 0) && (vect[j] > temp)) // внутренний цикл сортировки
		{
			vect[j + 1] = vect[j]; 
			--j;
		}

	vect[j + 1] = temp;
	}

	for (auto i = 0U; i < vect.size(); ++i) // вывод отсортированного вектора
	{
		std::cout << vect[i] << ", ";
	}

	system("pause");
	return 0;
}