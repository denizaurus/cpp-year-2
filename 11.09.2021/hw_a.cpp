/* �������� � ��������� ASCII, � ����� �������� ������ (e.g. ���������� �������� ������� � ������� ��������� ord). */
/* �������� �� ����� ����� (Ctrl+Z), ���������� ����� � ������ ������� ��������� ������. */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


int main()
{
	std::string input, temp;
	std::vector < std::string > output;
	int ord_f, ord_b;

	while (std::cin >> input) // � ����� ���������� �� ����� �����
	{
		ord_f = (int)input.front();
		ord_b = (int)input.back();

		if ((32 < ord_f) && (ord_f < 47)) // ��� ���������� ������� ����� ������� �������� �����, ��� ��� ���������
		{
			temp.push_back(input.front());
			output.push_back(temp);
			temp.pop_back();

			input = input.substr(1);
		}



		if (input != "")
		{

			if (((32 < ord_b) && (ord_b < 47)) ||
				((57 < ord_b) && (ord_b < 65)))
			{
				temp.push_back(input.back());
				input.pop_back();
			}

			output.push_back(input);

			if (temp.size())
			{
				output.push_back(temp);
				temp.pop_back();
			}
		}

	}

	for (auto i = 0U; i < output.size(); ++i)
	{
		std::cout << output[i] << '\n';
	}

	system("pause");
	return 0;
}