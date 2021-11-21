#include < iostream >

template < size_t N >
struct fib
{
	const static inline auto value = fib < N - 1 > ::value + fib < N - 2 > ::value;
};

template <>
struct fib < 0 >
{
	const static inline size_t value = 0;
};

template <>
struct fib < 1 >
{
	const static inline size_t value = 1;
};

template < size_t N >
inline constexpr auto fib_v = fib < N > ::value;

int main()
{
	std::cout << fib_v < 17 > << std::endl;
}