/* Ðàáîòàåò ñ ñèìâîëàìè ASCII, ñ èíûìè âûçûâàåò îøèáêè (e.g. ìíîãîòî÷èå ïðîõîäèò óñëîâèÿ ñ íóëåâûì çíà÷åíèåì ord). */
/* Ðàáîòàåò äî êîíöà ââîäà (Ctrl+Z), ðåàëèçàöèÿ öèêëà ñ ïóñòîé ñòðîêîé íåñêîëüêî äðóãàÿ. */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


int main()
{
	std::string input, temp;
	std::vector < std::string > output;
	int ord_f, ord_b;

	while (std::cin >> input) // â òàêîé ðåàëèçàöèè äî êîíöà ââîäà
	{
		ord_f = (int)input.front();
		ord_b = (int)input.back();

		if ((32 < ord_f) && (ord_f < 47)) // äëÿ íà÷àëüíîãî ñèìâîëà ñëîâà êàðòèíà ñèòóàöèÿ ïðîùå, ÷åì äëÿ êîíå÷íîãî
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