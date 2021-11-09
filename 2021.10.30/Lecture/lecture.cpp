#include <vector>
#include <type_traits> // common...


template <typename T, std::size_t N> // for std array
void f{}

template <typename T>
T max(T a, T b)
{
	return b < a ? a : b;
}

//optimize max
template < typename T1, typename T2 >
auto max_1(T1 a, T2 b)
{
	return b < a ? a : b;
}

//alt
// template <typename RT, typename T1, typename T2>  defining return type separately
// RT max... -> max(42, 43.0) won't work -> need max <double> (42, 43.0) 
// <> arguments follow order in template so double is RT;


template <typename	T1, typename T2,
	typename RT = std::common_type_t < T1, T2 > >
	RT max_2() {};


template < typename T >
class Stack
{
public:
	const T & top() const;
	void pop();
	void push(const T & v);
	bool empty() const
	{
		return values.empty();
	}
private:
	std::vector < T > values;
};


template < typename T > // define methods outside of class
const T & Stack < T > ::top() const
{
	if (empty())
	{
		// ...
	}

	return values.back()
}


int main()
{
	//auto m = max(42, 43); // can omit int bc compilator can understand 42 and 43 are ints
	//auto m = max < int >(42, 43); // equal to previous

	//auto m = max(42, 43.0); // throws without static cast, < double > or T1 T2 IN TEMPLATE
}

