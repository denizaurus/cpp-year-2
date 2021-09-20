#include <iostream> 
#include <vector> 
#include <algorithm>

int main()
{
	std::vector < int > a = { 5, -8, 18, 93, 0, 75, -9, 8, 249 };
	
	auto ascend = [](auto first, auto second) {
		return (first <= second);
	};

	auto descend = [](auto first, auto second) {
		return (first >= second);
	};

	// SHOW ASCENDING VECTOR

	std::sort(a.begin(), a.end(), ascend);

	for (auto i = 0U; i < std::size(a); ++i)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';

	// 

	// SHOW DESCENDING VECTOR

	std::sort(a.begin(), a.end(), descend);

	for (auto i = 0U; i < std::size(a); ++i)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << '\n';

	//

	system("pause");
	return 0;
}