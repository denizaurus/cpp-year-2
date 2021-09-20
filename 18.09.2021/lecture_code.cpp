#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

void f(int x); //forward declaration, ����� �������� �, �� �� �����

//int main()
//{
//	// look through range-based-for
//	// f(42);
//
//	system("pause");
//	return 0;
//}
//
//void f(int x) 
//{
//
//}

//inline i
// int factorial(int n) // ����������� ����������� ������ �������� ���� ������� � ���. ������ ��������� ������; < 4 ����� (���������� 1-2)
//{
//	return (n > 1) ? n * factorial(n - 1) : 1; //if else � ����� ������
//}


//void f()
//{
//	static int x = 0;
//
//	std::cout << x << std::endl;
//
//	++x;
//}
//
//
//
//int main()
//{
//	f();
//	f();
//	f(); // ����� - 0, 1, 2
//}

//////////////////////////////

void f(int x, int y, int z = 3)
{
	// ��������� �� ���������
}

//////////////////////////////

void print(int x)
{
	std::cout << x << std::endl;
}

void print(const std::string & x)
{
	std::cout << x << std::endl;
}

////////////////////////////////

void print(int x)
{
	std::cout << x << std::endl;
}

void (*print_ptr)(int);

//int main()
//{
//	void(*print_ptr)(int);
//
//	print_ptr = &print;
//
//	(*print_ptr)(42); // ������������ ��� �������� ������� � ������ �������
//	print_ptr(42);
//}

//////////////////////////////// ������-�������

int main()
{
	std::vector < int > v(10, 0);

	int y = 42;

	std::for_each(v.begin(), v.end(), [](auto & x) {++x; });
	std::for_each(v.begin(), v.end(), [y](auto & x) {x += y;});

	auto n = std::count_if(v.begin(), v.end(), [y](auto x) {return x < y; });

	auto x = [](int x) { std::cout << x; }; //
	std::cout << typeid(x).name() << std::endl; // ������� ���� ����� � ����, ��� ������� ����
	//��� ������������ �����������
}


void f(std::function < bool(int, int) > pred)
{
	// ...
}

