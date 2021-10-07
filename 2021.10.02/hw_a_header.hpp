#pragma once

#include <string>
#include <iostream>
#include <cmath>

class Weather
{

	friend void cold_check(const Weather &);

public:

	Weather() : date("1970-01-01"), def_temp('c'), temp_c(0.0), temp_f(0.0)
	{
		std::cout << "Default weather data for " << date << ".\n";
	}

	Weather(const std::string &, const char, const double);

	~Weather()
	{
		std::cout << "Weather data for " << date << " erased.\n";
	}

private:

	double convert_cf(double x) const
	{
		return std::lround(9.0 / 5.0 * x + 32.0);
	}

	double convert_fc(double x) const
	{
		return std::lround((x - 32.0) * 5.0 / 9.0);
	}

	std::string date;
	char def_temp;
	double temp_c;
	double temp_f;
};