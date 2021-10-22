#include "B_header.hpp"

int main()
{
// TESTING CODE

	Fraction f(-3, 9);   // -1/3
	Fraction g(1, 7);

	auto a = 10 + f;      // 29/3
	auto b = -7 * g;      // -1/1
	g += f;               // -4/21
	auto c = a * (1 / a); // 1/1  
	auto d = a + (- a);   // 0/1 

	std::cout << f << a << b << g << c << d << std::endl;

	std::cout << (g == f) << std::endl
		<< (g < f) << std::endl
		<< (g > -1) << std::endl
		<< (g >= 0) << std::endl
		<< (g <= 0) << std::endl
		<< (f != Fraction(-1, 3)) << std::endl;

	system("pause");
	return 0;
}