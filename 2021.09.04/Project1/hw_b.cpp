#include <iostream>
#include <iomanip>

int main()
{
	const int len_const = 100;
	const int weight_const = 1000;
	const long long int charge_const = 9000000000;

	double in;
	std::string var_convert;

	std::cout << "Convert from SI to CGS-ESU: (length/weight/charge)" << '\n';
	std::cout << "Input the variable:" << '\n';
	std::cin >> var_convert;
	std::cout << "Input the value in SI:" << '\n';
	std::cin >> in;

	if (var_convert == "length")
	{
		std::cout << '\n' << std::fixed << std::setprecision(3) << len_const * in << " centimetres.";
	}
	else if (var_convert == "weight")
	{
		std::cout << '\n' << std::fixed << std::setprecision(3) << weight_const * in << " grams.";
	}
	else if (var_convert == "charge")
	{
		std::cout << '\n' << std::fixed << std::setprecision(3) << charge_const * in << " statcoulombs.";
	}
	else
	{
		std::cout << "Unrecognised variable.";
	}

	system("pause");
	return 0;


}