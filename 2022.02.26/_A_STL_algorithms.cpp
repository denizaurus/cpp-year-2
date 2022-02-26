#include < iostream >
#include < numeric >
#include < iterator >
#include < algorithm >
#include < random >

#include < vector >
#include < unordered_set >

bool is_prime(int num);
void output(const std::vector < int > & s);

class RNG
{
public:
	RNG(int seed, int low, int high) : m_re(seed), m_uid(low, high) {}

	int operator() () { return m_uid(m_re); }

private:
	std::default_random_engine m_re;
	std::uniform_int_distribution < int > m_uid;
};

int main()
{
	std::vector < int > s(10);
	std::default_random_engine dre(5);
	std::uniform_int_distribution uid(0, 100);

	std::iota(std::begin(s), std::end(s), 0); // 1

	std::copy(std::istream_iterator < int >(std::cin),
		std::istream_iterator < int >(),
		std::back_inserter(s)); // 2

	std::shuffle(std::begin(s), std::end(s), dre); // 3

			// output(s);

	std::unordered_set < int > s_set(std::cbegin(s), std::cend(s));
	s.assign(std::cbegin(s_set), std::cend(s_set)); // 4

			// output(s);

	std::cout << std::count_if(std::cbegin(s), std::cend(s), [](int y) { return y % 2 != 0; }) << std::endl; // 5

			// output(s);

	auto minmax = std::minmax_element(std::cbegin(s), std::cend(s));
	std::cout << "MIN: " << *minmax.first << " MAX: " << *minmax.second << std::endl; // 6

	auto prime = std::find_if(std::begin(s), std::end(s),
		[](const int & n) {if (is_prime(n)) { return n; }}); // 7

	std::cout << "Prime: " << *prime << std::endl;

	std::for_each(std::begin(s), std::end(s), [](int & k) { k *= k; }); // 8

			// output(s);

	std::vector < int > s2(std::size(s));
	std::generate(std::begin(s2), std::end(s2), RNG(5, 0, 100)); // 9

			// output(s2);

	std::cout << "SUM OF SEQUENCE 2: " << std::accumulate(std::begin(s2), std::end(s2), 0) << std::endl; // 10

	std::for_each_n(std::begin(s2), 5, [](int & k) { k = 1; }); // 11

			// output(s2);

	std::vector < int > s3(std::size(s)); 
	std::transform(std::cbegin(s), std::cend(s), std::cbegin(s2), 
		std::begin(s3), std::minus()); // 12

			// output(s3);

	std::for_each(std::begin(s3), std::end(s3), [](int & k) { if (k < 0) { k = 0; }}); // 13

	std::erase(s3, 0); // 14 // works since c++ 20

	std::reverse(std::begin(s3), std::end(s3)); // 15

	std::partial_sort(std::begin(s3), std::next(std::begin(s3), 3), std::end(s3), std::greater()); // 16

	std::sort(std::begin(s), std::end(s));
	std::sort(std::begin(s2), std::end(s2)); // 17

	std::vector < int > s4(std::size(s) + std::size(s2));
	auto it = std::set_union(std::cbegin(s), std::cend(s), 
		std::cbegin(s2), std::cend(s2), std::begin(s4));
	s4.erase(it, std::end(s4)); // 18

	auto range = std::equal_range(std::begin(s4), std::end(s4), 1); // 19


	std::cout << "s1: "; output(s);
	std::cout << "s2: "; output(s2);
	std::cout << "s3: "; output(s3);
	std::cout << "s4: "; output(s4); // 20

	system("pause");
	return 0;
}

bool is_prime(int num)
{
	if (num < 2) { return false; }

	for (int i = 2; 2 * i <= num; ++i)
	{
		if (num % i == 0) { return false; }
	}

	return true;
}

void output(const std::vector < int > & s)
{
	std::copy(std::cbegin(s), std::cend(s), std::ostream_iterator < int >(std::cout, " "));
	std::cout << std::endl;
}