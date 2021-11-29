#include < iostream >

constexpr double eps_approx(double eps)
{
	double value = 1.0;
	double factorial = 1.0;

	for (auto i = 1U; true; ++i)
	{
		factorial *= i;

		double cur_member = 1.0 / factorial;
		if (cur_member < eps) break;

		value += cur_member;
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