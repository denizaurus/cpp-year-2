#include "D_MixIn.hpp"

int main()
{
	std::string prof = "Test";
	auto calc = Calculus(false, prof);
	calc.diligenceRating();

	return 0;
}