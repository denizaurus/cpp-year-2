#include "A_header.hpp"

int main()
{

	std::vector < int > v1 = { 1, 2, 3, 6 };
	std::vector < int > v2 = { 1, 3, 7, 19, 25 };

	int * arr = new int[4];

	for (auto i = 0U; i < 4; ++i)
	{
		arr[i] = v1[i];
	}

	Storage first;
	Storage second(v1);
	Storage third(arr, 4);
	Storage fourth(arr, 4, v2);

	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << third << std::endl;
	std::cout << fourth << std::endl;

	Storage fifth = second;
	Storage sixth = std::move(fourth);

	Storage seventh(second);
	Storage eighth(std::move(second));


	std::cout << fifth << std::endl;
	std::cout << sixth << std::endl;
	std::cout << fourth << std::endl;

	std::cout << std::endl;

	std::cout << seventh << std::endl;
	std::cout << eighth << std::endl;
	std::cout << second << std::endl;

	delete[] arr;

	return 0;
}