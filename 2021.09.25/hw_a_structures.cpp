#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>


struct Weather
{
	std::string date;
	char def_temp;
	double temp_c;
	double temp_f;

	Weather() : date("01.01.1970"), def_temp('c'), temp_c(0.0), temp_f(0.0)
	{
		std::cout << "Default weather data for " << date << ".\n";
	}

	Weather(const std::string & d, const char deg, const int t):
		date(d), def_temp( std::tolower(deg) ), temp_c(0.0), temp_f(0.0)
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

	~Weather()
	{
		std::cout << "Weather data for " << date << " erased.\n";
	}

	double convert_cf(double x) const
	{
		return std::lround(9.0 / 5.0 * x + 32.0);
	}

	double convert_fc(double x) const
	{
		return std::lround((x - 32.0) * 5.0 / 9.0);
	}
};


int main()
{
	Weather p("25 January", 'F', 52.0);
	std::cout << p.temp_c << std::endl;
	return 0;
}