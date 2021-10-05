#include <string>
#include <vector>
#include <bitset>
#include <iostream>
#include <iomanip>


struct Date
{
	Date(size_t ms, size_t s, size_t mi, size_t h, size_t d, size_t mo, size_t y):
		msecond(ms), second(s), minute(mi), hour(h), 
		day(d), month(mo), year(y)
	{
		std::cout << "Compiling structure. . ." << std::endl;
	}

	size_t msecond : 10;
	size_t second : 6;
	size_t minute : 6;
	size_t hour : 5;
	
	size_t day : 5;
	size_t month : 4;
	size_t year : 12; // 48 bit

	void output()
	{
		std::cout << "Date stored: " << std::setw(2) << std::setfill('0') << hour << ':' <<
			std::setw(2) << minute << ':' << 
			std::setw(2) << second << '.' <<
			std::setw(3) << std::setfill('0') << msecond << " " <<
			year << '.' << 
			std::setw(2) << month << "." << 
			std::setw(2) << day << std::endl;
	}
};


int main()
{
	Date d(125, 5, 4, 3, 30, 9, 2021);
	d.output();

	system("pause");
	return 0;
}