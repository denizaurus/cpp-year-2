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

	std::bitset<10> msecond;
	std::bitset<6> second;
	std::bitset<6> minute;
	std::bitset<5> hour;

	std::bitset<5> day;
	std::bitset<4> month;
	std::bitset<12> year; // 48 bit

	void output()
	{
		std::cout << "Date stored: " << std::setw(2) << std::setfill('0') << hour.to_ulong() << ':' <<
			std::setw(2) << minute.to_ulong() << ':' <<
			std::setw(2) << second.to_ulong() << '.' << 
			std::setw(3) << std::setfill('0') << msecond.to_ulong() << " on "
			<< year.to_ulong() << '.' << month.to_ulong() << "." << day.to_ulong() << std::endl;
	}

};


int main()
{
	Date d(125, 5, 4, 3, 30, 9, 2021);
	d.output();

	system("pause");
	return 0;
}