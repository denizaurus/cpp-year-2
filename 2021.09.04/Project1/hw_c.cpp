#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
	double a, b, c;
	double D, sol_1, sol_2;
	const double constexpr epsilon =
		std::numeric_limits < double > ::epsilon();

	std::cout << "Solve the quadratic equation.\nInput a: (a =/= 0)\n";
	std::cin >> a;

	while (std::abs(a) < epsilon)
	{
		std::cout << "Invalid input.\nInput a: (a =/= 0)\n";
		std::cin >> a;
	}

	std::cout << "Input b:\n";
	std::cin >> b;
	std::cout << "Input c:\n";
	std::cin >> c;

	D = std::pow(b, 2) - 4 * a * c;

	if (std::abs(D) < epsilon)
	{
		sol_1 = -b / (2 * a);
		std::cout << "\nSolution: " << std::fixed << std::setprecision(3) << sol_1 << '\n';
	}

	else if (D < 0)
	{
		std::cout << "\nNo real solutions found." << '\n';
	}
	
	else 
	{
		sol_1 = (-b + std::sqrt(D)) / (2 * a);
		sol_2 = (-b - std::sqrt(D)) / (2 * a);
		std::cout << "\nSolutions:\n" << std::fixed << std::setprecision(3) << sol_1 << '\n' << std::fixed << std::setprecision(3) << sol_2 << '\n';
	}

	system("pause");
	return 0;
}	