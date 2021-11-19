#include < iostream >
#include < vector >
#include < type_traits >

template < typename T, typename... Types >
auto dynamic(Types... args)
{
	return new T(args...);
}


int main()
{
	std::vector < int > temp = { 5, 4, 2 };

	auto a = dynamic < int > (5);
	auto b = dynamic < std::vector < int > >(std::begin(temp), std::end(temp));

	std::cout << *a << std::endl;
	std::cout << (*b)[2] << std::endl;
}
