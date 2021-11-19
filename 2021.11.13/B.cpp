template < typename T >
struct add_const { using type = const T; };
// could be mistaken but i think it should work for const& without the & variation?

template < typename T >
using add_const_t = add_const < T > ::type;



template < typename T > 
struct remove_const { using type = T; };

template < typename T >
struct remove_const < const T > { using type = T; };

template < typename T >
using remove_const_t = remove_const < T > ::type;