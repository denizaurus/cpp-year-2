#include < iostream >
#include < array >

template < size_t N > // haven't found a different way to pass the size to std array
constexpr size_t prime_find()
{
	std::array < size_t, N > primes;
	primes[0] = 2U;
	auto num = 1U;

	for (auto i = 3U; num < N; ++i)
	{
		if (check_prime < N >(primes, i))
		{
			primes[num] = i;
			++num;
		}	
	}

	return primes.back();
}

template < size_t N >
bool check_prime(std::array < size_t, N > primes, size_t num)
{
	for (auto prime : primes)
	{
		if (prime > num / 2)
			return true;
		else if (num % prime == 0)
			return false;
	}
	return true;
}


int main()
{
	std::cout << prime_find <17> ();
}