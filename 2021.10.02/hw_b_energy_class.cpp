#include <iostream>
#include <string>
#include <cmath>

class Energy
{
	const static inline double j_erg = 1e7;
	const static inline double j_elvolt = 6.242e18;
	double joules;

public:

	void setter(const std::string &, double);
	double get_value(const std::string &);
};

void Energy::setter(const std::string & unit, double val)
{
	if (unit == "joule")
	{
		joules = val;
	}
	else if (unit == "erg")
	{
		joules = val / j_erg;
	}
	else if (unit == "electronvolt")
	{
		joules = val / j_elvolt;
	}
	else
	{
		std::cerr << "Invalid unit.\n";
	}
}

double Energy::get_value(const std::string & unit)
{
	double return_value = 0.0;

	if (unit == "joule")
	{
		return_value = joules;
	}
	else if (unit == "erg")
	{
		return_value = joules * j_erg;
	}
	else if (unit == "electronvolt")
	{
		return_value = joules * j_elvolt;
	}
	else
	{
		std::cerr << "Invalid unit.\n";
	}

	return return_value;
}

int main()
{
	Energy e;
	e.setter("erg", 125);
	std::cout << e.get_value("electronvolt") << " eV.\n";
	return 0;
}