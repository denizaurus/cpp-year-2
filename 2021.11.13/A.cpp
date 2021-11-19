#include < iostream >
#include < iomanip >

template < typename T, typename... Types >
struct is_function : std::false_type {};

template < typename T, typename... Types >
struct is_function < T(Types...) > : std::true_type {};

template < typename T, typename... Types >
inline constexpr bool is_function_v = is_function < T, Types... > ::value;

void f(int x) {}

int main()
{
	std::cout << std::boolalpha << is_function_v < int > << std::endl;
	std::cout << is_function_v < int(int) > << std::endl;
	std::cout << is_function_v < decltype(f) > << std::endl;
}