#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>

double calculate(double first, double second, std::function < double(double, double) > lambda)
{
	return lambda(first, second);
}

int main()
{
	double a = 1.258;
	double b = 7.548;
	std::vector <std::function < double(double, double) > > lambdas;

	lambdas.push_back([](double x, double y) {return x + y; });
	lambdas.push_back([](double x, double y) {return x - y; });
	lambdas.push_back([](double x, double y) {return x * y; });
	lambdas.push_back([](double x, double y) {return x / y; });

	for (auto i = 0U; i < std::size(lambdas); ++i)
	{
		std::cout << std::fixed << std::setprecision(3) <<
			calculate(a, b, lambdas[i]) << '\n';
	}

	system("pause");
	return 0;
}

