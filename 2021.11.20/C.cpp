#include < iostream >
#include < cmath >
#include < numbers >

constexpr size_t factorial(size_t i)
{
	if (i == 0) return 1;
	else return factorial(i - 1) * i;
}

constexpr double eps_approx(double eps)
{
	auto e = std::numbers::e;
	double value = 1.0;

	for (auto i = 1U;
		(e - value) > eps;
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