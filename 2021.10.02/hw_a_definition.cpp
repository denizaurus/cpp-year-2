#include <iostream>
#include <cctype>
#include <string>

#include "hw_a_header.hpp"

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

void cold_check(const Weather & day)
{
	if (day.temp_c < 0.0)
	{
		std::cout << "Brr, cold!\n";
	}
}