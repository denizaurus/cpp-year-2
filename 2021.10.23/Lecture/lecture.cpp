#include <iostream>
#include <vector>
#include <cassert>
#include <string>

//#define ABC 42;
//#define max(x, y) (x < y ? y : x) // copies this and pastes into code
//
//#ifdef _NDEBUG  // look up in project settings, doesn't work as it should, preprocessor in c++ properties 
//#  define ABC 0
//#else
//#  define ABC 1
//#endif
//
//int main()
//{
//	int x = 42;
//	int y = ABC; //don't overuse macros, this is a study example
//
//	int z = max(x, y);
//
//	int a = 0;
//	int b = 1;
//	int c = max(a++, b++);
//	std::cout << c << ' ' << a << ' ' << b << ' ' << std::endl; // RETURNS 2, 1, 3 due to copypasting
//	// c = ( x++ < y++ ? y++ : x++ )
//
//	std::cout << __FILE__ << __LINE__ << std::endl; // filename and line number
//
//	// assert(x == 41); throws
//
//	int * ptr = nullptr;
//	// assert(ptr); // assert is purple bc assert is a macros
//
//
//	system("pause");
//	return EXIT_SUCCESS;
//}


void g()
{
	int x = 41;
	if (x != 42)
	{
		throw std::exception("error"); // base exception class
		// domain_error - argument not within the expected ones; also invalid_argument
		throw 42; // exception type int
		throw "error"; // both possible, shouldn't do that, catch(...) will work; exception type const char[6]
	}
}

void h() { g(); };
void f() { h(); };


int main()
{
	try
	{
		int x = 42;
		f(); // creates exception -- exit try
		int y = 43; // y will not be defined

		// if x is new, y is delete, this is very dangerous. solve by RAII
	}
	catch (const std::runtime_error & e)
	{
		std::cerr << e.what() << std::endl; 
		// what is a virtual function, returns what is defined in the constructor
	}
	catch (const std::logic_error & e)
	{
		// ... std:cout something
		throw std::exception("error"); // can do that
	}
	catch (const std::exception & e) // if put before others, those won't work, this covers everything
	{
		// ...
	}
	catch (...) // catch all, e.g. you write an exception and forget to add to the hierarchy
	{
		std::cerr << "unknown exc\n";
		// 
	}

	return 0;
}

class X {};
//
//X::~X() noexcept
//{
//	try
//	{
//
//	}
//	catch
//	{
//		std::abort();
//	}
//}

//const auto & get() const noexcept(noexcept(f)) // not recommended
//{
//	return f();
//} // CLASS GETTER

class My_Exception : public std::exception
{
public:
	My_Exception(const std::string & s) : std::exception(s.c_str()) {}

	~My_Exception() noexcept = default;

	// ...

	const char * what() const override
	{
		// ...
	}
};