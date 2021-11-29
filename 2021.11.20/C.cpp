#include < iostream >
#include < cmath >

constexpr double eps_approx(double eps)
{
	double value = 1.0;
	double epsilon = 1.0 / eps;

	for (auto i = 1U; true; ++i)
	{
		double factorial = 1.0;
		for (auto j = i; j > 1.0; --j) { factorial *= j; }

		if (factorial > epsilon) break;

		value += 1.0 / factorial;
	}

	return value;
}


int main()
{
	constexpr auto e1 = eps_approx(0.001);
	constexpr auto e2 = eps_approx(0.0000001);

	std::cout << e1 << std::endl;
	std::cout << e2 << std::endl;

	return 0;
}