#include < iostream >
#include < format >

template < uint64_t K, uint64_t N >
struct Binomial
{
	const static inline uint64_t value =
		Binomial < K - 1, N - 1 > ::value + Binomial < K, N - 1 > ::value;
};

template < uint64_t N >
struct Binomial < N, N >
{
	const static inline uint64_t value = 1;
};

template < uint64_t N >
struct Binomial < 0, N >
{
	const static inline uint64_t value = 1;
};

template < uint64_t K, uint64_t N > 
inline constexpr auto Binomial_v = Binomial < K, N > ::value;


int main()
{
	std::cout << std::format("Binomial({}, {}): ", 34, 67) << Binomial_v < 34, 67 > << std::endl;
	system("pause");
	return 0;
}
