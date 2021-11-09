#include <iostream>
#include <vector>
#include <array>
#include <type_traits>

// Обобщенное программирование

template < typename T, std::size_t N > // old: class
void f(std::vector < T > & v)
{}

template < typename T1, typename T2, 
	typename RT = std::common_type_t < T1, T2 > >
RT max(T1 a, T2 b)
{
	return b < a ? a : b;
}

int max(int a, int b)
{
	return b < a ? a : b;
}

// Инстанцирование - 2 этапа
// 1. Проверка кода без подстановки конректного типа
// 2. Проверка кода с подстановкой конректного типа

template < typename T /*, typename C = std::vector < T >*/ >
class Stack
{
public:
	const T & top() const;
	void pop();
	// void pop(T & result);
	void push(const T & v);
	bool empty() const
	{
		return values.empty();
	}
private:
	std::vector < T > values;
};

template < typename T >
const T & Stack < T > ::top() const
{
	if (empty())
	{
		// ...
	}

	return values.back();
}

template < typename T >
void Stack < T > ::pop()
{
	if (empty())
	{
		// ...
	}

	values.pop_back();
}

template < typename T >
void Stack < T > ::push(const T & v)
{
	values.push_back(v);
}

// Специализация

template <>
class Stack < std::string >
{
public:
	const std::string & top() const;
	void pop();
	// void pop(T & result);
	void push(const std::string & v);
	bool empty() const
	{
		return values.empty();
	}
private:
	std::vector < std::string > values;
};

#include <deque>

//template < typename T >
//using StackD = Stack < T, std::deque < T > > ;

template < typename T1, typename T2 >
using common_type_t = typename std::common_type < T1, T2 > ::type;

template < typename T >
const T pi = T(3.141592);

template < typename T >
T area(T r)
{
	return pi < T > * r * r;
}

int main()
{
	Stack < int > s;
	Stack < std::string > s2;

	s.push(42);
	s.pop();

	//Stack < int, std::vector < int > > s3;
	//StackD < int > s4;

	int * ptr;
	if (ptr)
	{

	}
}


