#include <iostream>
#include <cctype>
#include <string>

#include "hw_a_basic_class.hpp"

Weather::Weather() : date("1970-01-01"), def_temp('c'), temp_c(0.0), temp_f(0.0)
{
	std::cout << "Default weather data for " << date << ".\n";
}

Weather::Weather(const std::string & d, const char deg, const double t) :
	date(d), def_temp(std::tolower(deg)), temp_c(0.0), temp_f(0.0)
{
	std::cout << "Assembling weather data for " << date << ".\n";

	(def_temp == 'c') ? (temp_c = t) : (temp_f = t);

	if (def_temp == 'c')
	{
		temp_f = convert_cf(temp_c);
	}
	else if (def_temp == 'f')
	{
		temp_c = convert_fc(temp_f);
	}
}

double Weather::convert_cf(double x) const
{
	return std::lround(9.0 / 5.0 * x + 32.0);
}

double Weather::convert_fc(double x) const
{
	return std::lround((x - 32.0) * 5.0 / 9.0);
}

void cold_check(Weather & day)
{
	if (day.temp_c < 0.0)
	{
		std::cout << "Brr, cold!\n";
	}
}

int main() // usually put into another cpp file, pointless to do that here
{
	Weather a("Merry Chrysler", 'F', 30.0);
	cold_check(a);
	return 0;
