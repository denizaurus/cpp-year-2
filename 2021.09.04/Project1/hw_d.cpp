#include <iostream>

int main()
{
	int a = 5;
	int b = 9;

	b += a;
	a = b - a;
	b -= a;

	std::cout << "a: " << a << " b: " << b << '\n';

	system("pause");
	return 0;
}