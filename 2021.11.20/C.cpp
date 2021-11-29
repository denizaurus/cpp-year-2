#include < iostream >
#include < cmath >

constexpr size_t factorial(size_t i)
{
	if (i == 0) return 1;
	else return factorial(i - 1) * i;
}

constexpr double eps_approx(double eps)
{
	double value = 1.0;
	double epsilon = 1.0 / eps;

	for (auto i = 1U;
		factorial(i) < epsilon;
		++i)
	{
		value += 1.0 / factorial(i);
	}

	return value;
}


int main()
{
	std::cout << eps_approx(0.001) << std::endl;
	std::cout << eps_approx(0.0000001) << std::endl;

	return 0;
}