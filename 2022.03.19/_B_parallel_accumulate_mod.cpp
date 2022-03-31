#include <thread>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include "timer.hpp"

template < typename Iterator, typename T >
struct accumulate_block
{
	void operator()(Iterator first, Iterator last, T & result)
	{
		result = std::accumulate(first, last, result); // !
	}
};

template < typename Iterator, typename T >
T parallel_accumulate(Iterator first, Iterator last, T init, size_t num_threads)
{
	const std::size_t length = std::distance(first, last);

	if (!length)
		return init;

	const std::size_t block_size = length / num_threads;

	std::vector < T > results(num_threads);
	std::vector < std::thread > threads(num_threads - 1);

	Iterator block_start = first;

	for (std::size_t i = 0; i < (num_threads - 1); ++i)
	{
		Iterator block_end = block_start;
		std::advance(block_end, block_size);

		threads[i] = std::thread(
			accumulate_block < Iterator, T >(),
			block_start, block_end, std::ref(results[i])); // !

		block_start = block_end;
	}

	accumulate_block < Iterator, T >()(block_start, last, results[num_threads - 1]);

	std::for_each(threads.begin(), threads.end(),
		std::mem_fn(&std::thread::join));

	return std::accumulate(results.begin(), results.end(), init);
}


int main(int argc, char ** argv)
{
	const auto max_threads = 100U;
	std::vector < int > nums(200'000'000);
	std::iota(std::begin(nums), std::end(nums), 1);

	for (auto i = 0U; i < max_threads; ++i)
	{
		std::vector < int > for_averaging(10);
		std::generate(std::begin(for_averaging), std::end(for_averaging), [&nums, i]() {

			Timer timer(1);
			auto temp = parallel_accumulate(std::cbegin(nums), std::cend(nums), 0LL, i + 1U);
			timer.pause();
			timer.end(true);
			return timer.extract(); 
			}
		);

		std::cout << i + 1 << ' ' << std::accumulate(std::begin(for_averaging), std::end(for_averaging), 0) / 10.0 << std::endl;
	}

	return 0;
}