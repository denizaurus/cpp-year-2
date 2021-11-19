template < bool Bool, typename T = void >
struct enable_if {};

template < typename T >
struct enable_if < true, T > { using type = T; };

template < bool Bool, typename T = void >
using enable_if_t = enable_if < Bool, T > ::type;