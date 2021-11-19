#include <iostream>
#include <string>
#include <utility>
#include <type_traits>

// по значению
// копирование (оптимизации)
// std::ref(...) std::cref(...)
// безопаснее в return

// по ссылке
// производительность
// модификация (X &)
// пробрасываемость

// Правила свертывания ссылок:
// && &, & &&, & & -> &
// && && -> &&

// Правила вывода типа:

template < typename T >
void f(T & arg) {}
// int x = 42;          f(x);  T = int, arg = int &
// const int cx = 42;   f(cx); T = const int, arg = const int &
// const int & rx = cx; f(rx); T = const int, arg = const int &

template < typename T >
void f(T && arg) {}
// int x = 42;          f(x);  T = int&, arg = int& && -> int&
// const int cx = 42;   f(cx); T = const int&, arg = const int &
// const int & rx = cx; f(rx); T = const int&, arg = const int &
//                      f(42); T = int, arg = int&&
//                      f(std::move(x)); T = int&&, arg = int&& && -> int&&

void f(int && arg) {}

template < typename T >
void f(T arg) {} // тривиально - decay-преобразование

// также применимо для auto &&

// Реализация шаблонов свойств
// 1. проверяющие -> True|False
// 2. выводящие/создающие/преобразующие -> Type

class Person
{
public:

	//explicit Person(const std::string & name) :
	//	m_name(name)
	//{
	//	std::cout << "copying string for '" << m_name << "'\n";
	//}

	//explicit Person(std::string && name) :
	//	m_name(std::move(name))
	//{
	//	std::cout << "moving string for '" << m_name << "'\n";
	//}

	// Идиома SFINAE - substitution failure is not an error

	// std::enable_if_t < Condition >
	// std::enable_if_t < True  > -> void
	// std::enable_if_t < False > -> 
	// std::enable_if_t < True, X > -> X 
	// std::enable_if_t < False, X > ->  

	template < typename S, typename Enable =
		std::enable_if_t < std::is_convertible_v < S, std::string > > >
	explicit Person(S && name) : 
		m_name(std::forward < S > (name))
	{
		std::cout << "CTOR\n";
	}

	Person(const Person & person) :
		m_name(person.m_name)
	{
		std::cout << "COPY-CTOR Person '" << m_name << "'\n";
	}

	Person(Person && p) noexcept :
		m_name(std::move(p.m_name))
	{
		std::cout << "MOVE-CTOR Person '" << m_name << "'\n";
	}

	~Person() noexcept = default;

private:

	std::string m_name;
};

int main(int argc, char ** argv)
{
	std::string s = "Ivan";

	Person p1(s);
	Person p2("tmp");
	Person p3(p1);
	Person p4(std::move(p1));

	system("pause");

	return EXIT_SUCCESS;
}