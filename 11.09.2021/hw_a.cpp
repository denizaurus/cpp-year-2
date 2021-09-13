#include <iostream>
#include <iomanip>
#include <string>
#include <vector>


int main()
{
	std::string str = "Want to spell you with just the letter U? Or skip words altogether? (\"Sup?\")?";
	unsigned int first = 0;

	std::vector < char > sym = { ' ', '	', '\n', ',', '.', ':', ';', '!', '?', '\"', '\'', '(', ')' };
	std::vector < char > tab = { ' ', '	', '\n' }; // in order: space, tab

	std::vector < char > ::iterator vec_sym;
	std::vector < char > ::iterator vec_tab;

	std::vector < std::string > output;

	for (auto last = 0U; last < std::size(str); ++last)
	{
		vec_sym = std::find(sym.begin(), sym.end(), str[last]);
		vec_tab = std::find(tab.begin(), tab.end(), str[last]);

		if (vec_sym != sym.end())
		{

			if (first != last)
			{
				output.push_back(str.substr(first, last - first));
			}

			if (vec_tab == tab.end())
			{
				output.push_back(std::string(1, str[last]));
			}

			first = last + 1;
		}
	}

	for (auto i = 0U; i < std::size(output); ++i)
	{
		std::cout << output[i] << '\n';
	}

	system("pause");
	return 0;
}