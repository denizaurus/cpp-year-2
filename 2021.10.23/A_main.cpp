#include <variant>
#include <iostream>

enum class Err
{
	INVALID_ARGUMENT = 100,
	ZERO_DIVISION,
	MEMORY_ACCESS,
};

class CustomType
{
public:
	explicit CustomType() : value(15.0) {}
	explicit CustomType(double x) : value(x) {}

	double value;
};

// pointers are used specifically for memory access error

std::variant <CustomType, int> divide(CustomType * ptr, double divisor)
{
	if (not ptr)
	{
		return static_cast < int > (Err::MEMORY_ACCESS);
	}

	else if (divisor == 0.0)
	{
		return static_cast < int > (Err::ZERO_DIVISION);
	}

	else if (ptr->value != 15.0)
	{
		return static_cast < int > (Err::INVALID_ARGUMENT);
	}

	else
	{
		return CustomType(ptr->value / divisor);
	}

}

int main()
{
	CustomType a;
	CustomType b(25.0);

	std::cout << std::get < int > (divide(&b, 5.0)) << std::endl;
	std::cout << std::get < int > (divide(&a, 0)) << std::endl;
	std::cout << std::get < int > (divide(nullptr, 0)) << std::endl;
	std::cout << std::get < CustomType > (divide(&a, 5.0)).value << std::endl;

	system("pause");
	return 0;
}