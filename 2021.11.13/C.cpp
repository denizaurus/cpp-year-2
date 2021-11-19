//  If possible, could you clarify why simply removing references is enough to convert l to r-value (definition of decay)?


#include < type_traits >
#include < iostream >
#include < iomanip >



template < typename T >
struct remove_reference
{
    using type = T;
};

template < typename T >
struct remove_reference < T & >
{
    using type = T;
};

template < typename T >
struct remove_reference < T && >
{
    using type = T;
};

template < typename T > 
using remove_reference_t = remove_reference < T > ::type;



template < typename T >
struct is_array : std::false_type
{};

template < typename T, std::size_t N >
struct is_array < T[N] > : std::true_type
{
    using type = T;
    static constexpr std::size_t size = N;
};

template < typename T >
struct is_array < T[] >  : std::true_type
{
    using type = T;
    static constexpr std::size_t size = 0;
};

template < typename T >
inline constexpr bool is_array_v = is_array < T > ::value;



template < typename T >
struct array_to_pointer { using type = T *; };

template < typename T, size_t N > 
struct array_to_pointer < T[N] > { using type = T *; };

template < typename T >
struct array_to_pointer < T[] >  { using type = T *; };

template < typename T > 
using array_to_pointer_t = array_to_pointer < T > ::type;



template < typename T, typename... Types >
struct is_function : std::false_type {};

template < typename T, typename... Types >
struct is_function < T(Types...) > : std::true_type {};

template < typename T, typename... Types >
inline constexpr bool is_function_v = is_function < T, Types... > ::value;



template < typename T >
struct remove_const { using type = T; };

template < typename T >
struct remove_const < const T > { using type = T; };

template < typename T >
using remove_const_t = remove_const < T > ::type;



template < typename T > 
class proper_decay
{

private:
    using RawT = remove_reference_t < T >;

public:
    using type = std::conditional_t <
        is_array_v < RawT >,
        array_to_pointer_t < RawT >,
        std::conditional_t <
            is_function_v < RawT >,
            std::add_pointer_t < RawT >,
            remove_const_t < RawT > > >;
};



/*        TESTING         */

template <typename T, typename U>
struct decay_equiv :
    std::is_same < typename proper_decay <T>::type, U > ::type
{};

int main()
{
   
    std::cout << std::boolalpha
        << decay_equiv<int, int>::value << '\n'
        << decay_equiv<int &, int>::value << '\n'
        << decay_equiv<int &&, int>::value << '\n'
        << decay_equiv<const int &, int>::value << '\n'
        << decay_equiv<int[2], int *>::value << '\n'
        << decay_equiv<int(int), int(*)(int)>::value << '\n';
}