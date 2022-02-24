#include < iostream >
#include < set >
#include < vector >
#include < random >
#include < numeric >

#include "timer.hpp"

template < typename T >
void set_fill(const std::vector < T > & v)
{
	std::set < T > s;
	for (T element : v)
	{
		s.insert(element);
	}

	return;
}


int main(int argc, char ** argv)
{
	const size_t size = 100000;
	const size_t iter = 10;
	std::mt19937 gen(42);

	std::vector < int > set_t(10, 0);
	std::vector < int > vector_t(10, 0);

	std::vector < int > numbers(size, 0);
	std::iota(std::begin(numbers), std::end(numbers), 1);
	std::shuffle(std::begin(numbers), std::end(numbers), gen);

	Timer set("Set insert");
	Timer vector("Vector sort");

	for (auto i = 0U; i < iter; ++i)
	{
		set.start(1, 1);
		set_fill(numbers);
		set_t[i] = set.extract();

		vector.start(1, 1);
		std::sort(std::begin(numbers), std::end(numbers));
		vector_t[i] = vector.extract();
	}

	std::cout << "SET INSERT MEAN: " 
		<< std::accumulate(std::begin(set_t), std::end(set_t), 0) / iter << std::endl;

	std::cout << "VECTOR SORT MEAN: "
		<< std::accumulate(std::begin(vector_t), std::end(vector_t), 0) / iter << std::endl;

	system("pause");
	return 0;
}

// SET INSERT MEAN : 39663
// VECTOR SORT MEAN : 2408