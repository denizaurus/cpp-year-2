#include <exception>
#include <iostream>
#include <vector>
#include <cmath>

void f(const std::vector < double > & v, size_t x)
{
	if (x >= v.size())
	{
		throw std::out_of_range("Index out of range");
	}
	else if (v[x] <= 0.0) 
	{
		throw std::domain_error("Argument outside of function domain");
	}
	else
	{
		std::cout << std::log(v[x]) << std::endl;
	}
}

void g(const std::vector < double > & v, size_t x)
{
	try
	{
		f(v, x);
	}
	catch (const std::out_of_range & e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const std::domain_error & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	std::vector < double > v = { 1.0, 2.0, 3.0, -1.0 };
	
	g(v, 5);
	g(v, 3);
	g(v, 0);

	system("pause");
	return 0;
}

