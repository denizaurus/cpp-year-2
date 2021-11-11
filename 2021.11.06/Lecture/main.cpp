#include <iostream>
#include <tuple>
#include <any>
#include <string>
#include <vector>

// ����������� �������

// [N], std::array - ����������, �������������
// new[], std::vector - ����������, ������������
// std::pair, struct - ������������, �������������
// std::tuple(������) - ������������, ������������ (�� ����� ����������)
// std::vector < B* > - ������������, ������������ (runtime)
// std::vector < std::any > - ������������, ������������ (runtime) -> void*

// void f < T > (...) { T* t = new(...); }

// void f(...) {...} -> print

//void print() {}
//
//template < typename T, typename ... Types >
//void print(T arg, Types ... args)
//{
//	std::cout << arg << std::endl;
//
//	std::cout << "size: " << sizeof...(args) << std::endl;
//
//	//if (sizeof...(args) > 0)
//	print(args...);
//}

// ��������� �������

template < typename ... T >
auto sum(T ... s)
{
	return (... + s); // -> ((s1 + s2) + s3) + ...
}

// (... op P)
// (P op ...)
// (init op ... op P) -> ((init op p1) op p2) op ...
// (P op ... op init)

template < typename T >
class Spacer
{
public:
	explicit Spacer(const T & arg) : m_arg(arg) {}
	friend std::ostream & operator<<(
		std::ostream & stream, const Spacer < T > & s)
	{
		return (stream << s.m_arg << ' ');
	}
private:
	const T & m_arg;
};

template < typename ... Types >
void print(Types ... args)
{
	(std::cout << ... << Spacer(args)) << std::endl;
}

template < typename ... Types >
void f(Types ... args)
{
	print(args + 1 ...); // ����������� ���������
}

template < typename T1, typename ... TN >
bool is_homogenous(T1, TN ...) // type traits
{
	return (std::is_same_v < T1, TN > && ...);
}

// ����������� �������

template < typename C, typename ... Idx >
void print_by_idx(const C & c, Idx ... idx)
{
	print(c[idx]...);
}

template < std::size_t ... Idx, typename C >
void print_by_idx(const C & c)
{
	print(c[Idx]...);
}

// ����������� �����������
// ������������ �����������
// Shape - Circle, Triangle
// virtual void draw() const = 0; // -> override

void f(const Shape & s)
{
	s.draw();
}

template < typename S >
void f(const S & s)
{
	s.draw();
}

// ��������� �������
// ������� ��������

// CRTP - curiously recurrent template pattern

template < typename D >
class Base {};

class Derived : public Base < Derived > {};

int main()
{
	//print(42, 1.23, "hello");

	//f(1, 1.23, 42);

	//std::cout << std::boolalpha << is_homogenous(42, 17, 10.0) << std::endl;

	std::vector < int > v ={ 1, 2, 3, 4, 5 };

	print_by_idx(v, 0, 2, 3);
	print_by_idx < 0, 2, 3 > (v);
}