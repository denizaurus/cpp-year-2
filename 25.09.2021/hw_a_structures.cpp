#include <iostream>
#include <string>
#include <vector>


struct Weather
{
	std::string date;
	int temp_c;
	int temp_f;

	Weather() : date("01.01.1970"), temp_c(0), temp_f(0) 
	{
		std::cout << "Default weather data for " << date << ".\n";
	}

	Weather(const std::string & d, const char deg, const int t):
		date(d), temp_c(0), temp_f(0)
	{
		std::cout << "Assembling weather data for " << date << '\n';

		(deg == 'C' || deg == 'c') ? (temp_c = t) : (temp_f = t);

		switch (temp_c)
		{
		case 0:
			temp_c = convert_fc(temp_f);
			break;
		default:
			temp_f = convert_cf(temp_c);
		}
	}

	~Weather()
	{
		std::cout << "Weather data for " << date << " erased.\n";
	}

	int convert_cf(int x) const
	{
		return std::lround(9 / 5 * x + 32);
	}

	int convert_fc(int x) const
	{
		return std::lround((x - 32) * 5 / 9);
	}
};


int main()
{
	Weather p("25 January", 'F', 52);
	std::cout << p.temp_c;
	return 0;
}