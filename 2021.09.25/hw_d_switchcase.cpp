#include <iostream>
#include <string>
#include <vector>

enum class Months;
void determine(int);



int main()
{
	int month;
	
	std::cout << "Please input the number of the month:\n";
	std::cin >> month;

	determine(month);

	system("pause");
	return 0;
}

enum class Months {
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

void determine(int month)
{
	Months e_month = static_cast <Months> (month);

	switch (e_month)
	{
	case Months::JANUARY:
	case Months::MARCH:
	case Months::MAY:
	case Months::JULY:
	case Months::AUGUST:
	case Months::OCTOBER:
	case Months::DECEMBER:
		std::cout << "31 days.\n";
		break;
	case Months::APRIL:
	case Months::JUNE:
	case Months::SEPTEMBER:
	case Months::NOVEMBER:
		std::cout << "30 days.\n";
		break;
	case Months::FEBRUARY:
		std::cout << "Check the year. 28 or 29 days.";
		break;
	default:
		std::cerr << "Invalid input.\n";
	}
}