#include <iostream>
#include <string>
#include <map>

#include <cmath>
#include <algorithm>

class Energy
{

public:

	void setter(const std::string & unit, double val)
	{

		const auto search = conversion.find(unit); 
		// does not compile with std::find and iterators, i'm assuming it's defined in a map-specific way

		if (search != std::end(conversion))
		{
			value_j = val / search->second;
		}
		else
		{
			std::cout << "Invalid unit.";
		}
	}

	double get_value(const std::string & unit)
	{
		double return_value = 0.0;

		const auto search = conversion.find(unit);

		if (search != std::end(conversion))
		{
			return_value = value_j * search->second;
		}
		else
		{
			std::cout << "Invalid unit.";
		}
		return return_value;
	}

private:

	double value_j;

	const static inline std::map <std::string, double> conversion{
		{"erg", 1e7}, {"electronvolt", 6.242e18}, {"joule", 1},
	};
};


int main()
{
	Energy e;
	e.setter("erg", 125);
	std::cout << e.get_value("electronvolt") << " eV.\n";
	return 0;
}