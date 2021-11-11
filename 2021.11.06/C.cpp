#include < iostream >

template < typename T, typename... Types >
auto caller(T function, Types... args)
{
	return function(args...);
}

const char * f(const char * line, const char * line1)
{
	std::cout << "hello," << line;
	return line1;
}

int main()
{
	std::cout << caller(f, " ", "world");
}