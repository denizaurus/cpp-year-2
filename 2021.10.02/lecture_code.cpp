#include <iostream>
#include <string>
#include <vector>
#include "lecture_header.h"

class Demo
{
public:

private:

protected: // inheritance
};

//class Person
//{
//public:
//
//	Person(const std::string name) :
//		m_name(name), m_x(0) {}
//
//	explicit Person(int x) : // CANNOT call via =, only Person p(int)
//		m_name("name"), m_x(x) {}
//
//	Person(const std::string & name, int x) :
//		m_name(name), m_x(x) {}
//
//public:
//	const auto & name() const // const & or const class instances can only call const methods -- return const & of auto type (string)
//	{
//		return m_name;
//	}
//
//	void set_name(const std::string & s)
//	{
//		m_name = s;
//		//no point in setter for private data if the setter is trivial, jusg make the data public
//	}
//
//
//private:
//	std::string m_name;
//	int m_x; // m - member, good practice to add
//};
//
//int main()
//{
//	Person p("name");
//
//	Person p1 = std::string("name");
//
//	// Person p2 = 42; //valid without explicit but not preferable
//	// with explicit invalid
//
//	// Complex c = 42 // this is preferable, would be the real part; or fractions   // exam example
//}

extern int x;

//int main()
//{
//	Person p("name");
//
//	p.f(); // will throw, no definition
//
//	return 0;
//}

class X
{
public:
	static inline int x = 0; // the field is the same for all class instances
	// IT IS NOT INITIALIZED WITHOUT DEFINITION
};

/* or static int x = 0; later int X::x = 0*/

int main()
{
	X x1;
	X x2;

	x1.x = 42;
	std::cout << x2.x << std::endl;

	NS1::f();
}

namespace NS1
{
	void f() {}
}

namespace NS1
{
	void g() {} // NS1 will contain both f and g, additive even in different files
}

namespace NS1
{
	namespace NS2
	{
		void h() {};
	}
}