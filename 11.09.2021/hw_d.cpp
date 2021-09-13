#include <iostream>
#include <vector>
#include <cmath>
#include <string>

int main()
{
	std::string first, second, lcs;

	std::cin >> first;
	std::cin >> second;

	std::vector < std::vector < int > > m(first.size() + 1, std::vector < int > (second.size() + 1, 0));
	std::vector < int > output;

	int a = first.size() - 1;
	int b = second.size() - 1;
	int k;

	for (auto i = 1U; i <= first.size(); ++i)
	{
		for (auto j = 1U; j <= second.size(); ++j)
		{
			if (first[i - 1] == second[j - 1])
			{
				m[i][j] = m[i - 1][j - 1] + 1;
			}
			else
			{
				m[i][j] = std::max(m[i - 1][j], m[i][j - 1]);
			}
		}
	}

	while ((a >= 0) && (b >= 0))
	{
		if (first[a] == second[b])
		{
			output.push_back(a);
			--a; --b;						
		}
		else if (m[a][b + 1] > m[a + 1][b])
		{
			--a;
		}
		else
		{
			--b;
		}
	}

	for (int i = output.size() - 1; i >= 0; --i)
	{
		k = output[i];
		lcs.push_back(first[k]);
	}
	
	std::cout << lcs << '\n';

	system("pause");
	return 0;
}

