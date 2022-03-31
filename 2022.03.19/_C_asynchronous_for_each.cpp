#include <iostream>

#include <future>

#include <algorithm>
#include <functional>
#include <numeric>

template < typename Iterator, typename Function>
void for_each_async(Iterator begin, Iterator end, Function f)
{
	const size_t max_size = 64;
	auto length = std::distance(begin, end);

	if (length <= max_size) { std::for_each(begin, end, f); }
	else
	{
		Iterator mid = begin;
		std::advance(mid, length / 2);
		std::future < void > task1 = std::async(for_each_async < Iterator, Function >, begin, mid, f);
		for_each_async(mid, end, f);
	}
}

int main(int argc, char ** argv)
{
	std::vector < long long > numbers(100000);
	std::iota(std::begin(numbers), std::end(numbers), 1);
	for_each_async(std::begin(numbers), std::end(numbers), [](auto & t) { t = std::pow(t, 3); });

	return 0;
}