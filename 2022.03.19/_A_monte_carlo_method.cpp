#include <iostream>
#include <iomanip>

#include <future>
#include <vector>

#include <random>
#include <cmath>

double monte_carlo_sync(size_t);
double monte_carlo_async(size_t);

int main(int argc, char ** argv)
{
	std::cout << "SYNCHRONOUS: "  << std::setprecision(10) << monte_carlo_sync(10'000'000)     << std::endl;
	// 100'000'000 took 30 seconds, don't want to test on a billion
	std::cout << "ASYNCHRONOUS: " << std::setprecision(10) << monte_carlo_async(1'000'000'000) << std::endl;
	return 0;
}

double monte_carlo_sync(size_t dots)
{
	auto count = 0U;

	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_real_distribution<> real(-1.0, 1.0);

	for (auto i = 0U; i < dots; ++i)
	{
		auto x = real(gen);
		auto y = real(gen);

		if (std::pow(x, 2.0) + std::pow(y, 2.0) <= 1.0) { ++count; }
	}

	return (count * 4.0 / dots);
}

double monte_carlo_async(size_t dots)
{
	const auto max_per_thread = 10'000'000ULL;

	if (dots <= max_per_thread) { return monte_carlo_sync(dots); }
	else
	{
		std::future < double > first_half = std::async(monte_carlo_async, dots /= 2);
		double second_half = monte_carlo_async(dots /= 2);

		return (first_half.get() + second_half) / 2.0;
	}
}

/*
SYNCHRONOUS:  3.1409248
ASYNCHRONOUS: 3.141556752
PI:           3.1415926
*/