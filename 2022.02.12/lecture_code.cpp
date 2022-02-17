#include <iostream>
#include <tuple>

int main(int argc, char ** argv)
{

	std::tuple < int, double > t(42, 1.23);
	auto tu = std::make_tuple(42, 1.23);

	std::cout << std::get < 0 >(tu);

	int i; 
	double d;

	std::tie(i, d) = t;
	std::tie(i, std::ignore) = t; // unpacks only i

	system("pause");
	return 0;
}