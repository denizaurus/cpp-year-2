#include < iostream >
#include < vector >
#include < type_traits >

template < typename T, typename... Types >
std::common_type_t < T > * dynamic(Types... args)
{
	T * ptr = new T(args...);
	return ptr;
}


int main()
{
	std::vector < int > temp = { 5, 4, 2 };

	auto a = dynamic < int > (5);
	auto b = dynamic < std::vector < int > >(std::begin(temp), std::end(temp)); // works with N > 1 arguments
	// auto b = dynamic (6.52); // throws because it cannot deduce the type (std::common_type_t)
	std::cout << *a << std::endl;
	std::cout << (*b)[2] << std::endl;
}
