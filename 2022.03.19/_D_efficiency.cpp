#include <iostream>
#include <fstream>

#include <future>
#include <execution>

#include <algorithm>
#include <functional>
#include <numeric>
#include "timer.hpp"
#include "json.hpp"

template < typename Iterator, typename Function>
void for_each_async(Iterator begin, Iterator end, Function f)
{
	const size_t max_size = 100'000;
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
	const long long begin = 100'000;
	const long long end = 10'000'000;
	nlohmann::json json;

	std::vector <int> foreach(100);
	std::vector <int> foreach_async(100);
	std::vector <int> partial_sum(100);
	std::vector <int> inclusive_scan(100);
	std::vector <int> transform_reduce(100);
	std::vector <int> inner_product(100);

	for (auto i = 0U; i <= 100; ++i)
	{
		std::vector <int> foreach1(10);
		std::vector <int> foreach_async1(10);
		std::vector <int> partial_sum1(10);
		std::vector <int> inclusive_scan1(10);
		std::vector <int> transform_reduce1(10);
		std::vector <int> inner_product1(10);

		std::vector < long long > v((i + 1U) * begin);
		std::vector < long long > d((i + 1U) * begin);
		std::iota(std::begin(v), std::end(v), 1);

		for (auto j = 0U; j < 10; ++j)
		{
			Timer timer(1);
			std::for_each(std::begin(v), std::end(v), [](auto & t) { t *= 5; });
			foreach1[j] = timer.extract();

			timer.start(1, 1);
			for_each_async(std::begin(v), std::end(v), [](auto & t) { t *= 5; });
			foreach_async1[j] = timer.extract();

			timer.start(1, 1);
			std::partial_sum(std::begin(v), std::end(v), std::begin(d));
			partial_sum1[j] = timer.extract();

			timer.start(1, 1);
			std::inclusive_scan(std::execution::par, std::begin(v), std::end(v), std::begin(d));
			inclusive_scan1[j] = timer.extract();

			timer.start(1, 1);
			auto a = std::inner_product(std::begin(v), std::end(v), std::begin(d), 0LL);
			inner_product1[j] = timer.extract();

			timer.start(1, 1);
			auto b = std::transform_reduce(std::execution::par, std::begin(v), std::end(v), std::begin(d), 0LL);
			transform_reduce1[j] = timer.extract();

			if (a != b) { break; }
		}
		std::cout << i * begin << std::endl;
		foreach[i] = std::accumulate(std::begin(foreach1), std::end(foreach1), 0) / 10.0;
		foreach_async[i] = std::accumulate(std::begin(foreach_async1), std::end(foreach_async1), 0) / 10.0;
		partial_sum[i] = std::accumulate(std::begin(partial_sum1), std::end(partial_sum1), 0) / 10.0;
		inclusive_scan[i] = std::accumulate(std::begin(inclusive_scan1), std::end(inclusive_scan1), 0) / 10.0;
		transform_reduce[i] = std::accumulate(std::begin(transform_reduce1), std::end(transform_reduce1), 0) / 10.0;
		inner_product[i] = std::accumulate(std::begin(inner_product1), std::end(inner_product1), 0) / 10.0;
		
	}
	json["for_each"] = foreach;
	json["for_each_async"] = foreach_async;
	json["partial_sum"] = partial_sum;
	json["inclusive_scan"] = inclusive_scan;
	json["transform_reduce"] = transform_reduce;
	json["inner_product"] = inner_product;

	std::fstream fout("./results.json", std::ios::out);
	fout << json;

	return 0;
}