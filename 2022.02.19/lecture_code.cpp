#include <iostream>
#include <map>

int main(int argv, char ** argc)
{
	std::map < std::string, int > m;
	m["abc"] = 42;
	m.insert(std::make_pair("xyz", 43));

	try
	{
		   std::cout << m.at("a") << std::endl; // exception: invalid key
		// std::cout << m["a"] << std::endl; // if doesn't exist creates default and returns (0 in this case) -> [] is noexcept
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	for (const auto & [key, value] : m) // similar to python: enumerate
			// without const you can modify value, NOT KEY. with key only delete and recreate
	{
		std::cout << key << " " << value << std::endl;
	}

	system("pause");
	return 0;
}