
#pragma once

#include <string>

class Weather
{
	std::string date;
	char def_temp;
	double temp_c;
	double temp_f;

	double convert_cf(double) const;
	double convert_fc(double) const;

	friend void cold_check(Weather &);

public:

	Weather();

	Weather(const std::string &, const char, const double);

	~Weather()
	{
		std::cout << "Weather data for " << date << " erased.\n";
	}
};