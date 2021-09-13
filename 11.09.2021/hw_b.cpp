/* �������� �� ��������� ����� (Ctrl+Z) */

#include <iostream>
#include <vector>

int main()
{
	std::vector < int > vect;
	int temp, j, element;

	while (std::cin >> element) // ������ � ������
	{
		vect.push_back(element);
	}

	for (auto i = 1U; i < vect.size(); ++i) // ���������������� ���������� ���������
	{
	temp = vect[i];
	j = i - 1;

		while ((j >= 0) && (vect[j] > temp)) // ���������� ���� ����������
		{
			vect[j + 1] = vect[j]; 
			--j;
		}

	vect[j + 1] = temp;
	}

	for (auto i = 0U; i < vect.size(); ++i) // ����� ���������������� �������
	{
		std::cout << vect[i] << ", ";
	}

	system("pause");
	return 0;
}