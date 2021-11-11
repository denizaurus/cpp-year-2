#include < iostream >

template < typename... Types >
int arg_size(Types... args)
{
	return (sizeof(args) + ...);
}

int arg_size_2()
{
	return 0;
}

template < typename T, typename... Types >
int arg_size_2(T FirstArg, Types... args)
{
	return sizeof(FirstArg) + arg_size_2(args...);
}

int main()
{
	long long int k = 5;

	std::cout << arg_size(5, 5, k, 'a') << std::endl;
	std::cout << arg_size_2(5, 5, k, 'a') << std::endl;
}