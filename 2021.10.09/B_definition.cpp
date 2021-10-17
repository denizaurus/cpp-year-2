#include "B_header.hpp"
#include <numeric>

namespace tools
{
	int sign(int x)
	{
		return (x >= 0) ? 1 : -1;
	}

	std::vector < int > parse(std::string s)
	{
		std::vector out = { 0, 1 }; // num, den
		int temp_i;

		auto pos = s.find('/');
		if (pos == std::string::npos)
		{
			std::cout << "Invalid input.";
			return {};
		}

		temp_i = std::stoi(s.substr(0, pos));
		out[0] = temp_i;

		temp_i = std::stoi(s.substr(pos + 1));

		if (temp_i == 0)
		{
			std::cout << "Invalid input.";
			return {};
		}

		out[0] *= sign(temp_i);
		out[1]  = temp_i * sign(temp_i);

		return out;
	}
}


Fraction::Fraction() : 
	num(0), den(1) {}

Fraction::Fraction(int x) :
	num(x), den(1) {}

Fraction::Fraction(std::string input) : // public
	Fraction(tools::parse(input)) {}

Fraction::Fraction(std::vector < int > v) : // private
	num(v[0]), den(v[1]) 
{ 
	standardize(); 
}

void Fraction::standardize()
{
	int gcd = std::gcd(num, den);

	if (gcd != 1)
	{
		num /= gcd;
		den /= gcd;
	}

	num *= tools::sign(den);
	den *= tools::sign(den);
}

std::ostream & operator<< (std::ostream & stream, const Fraction & frac)
{
	stream << frac.num << "/" << frac.den << std::endl;
	return stream;
}

std::istream & operator>> (std::istream & stream, Fraction & frac)
{
	stream >> frac.num;
	stream >> frac.den; // can input two numbers separated by a whitespace
	frac.standardize();

	return stream;
}

// COPY ASSIGNMENT OPERATORS

Fraction & Fraction::operator+= (const Fraction & other)
{
	num = num * other.den + den * other.num;
	den *= other.den;
	standardize();
	return *this;
}

Fraction & Fraction::operator-= (const Fraction & other)
{
	num = num * other.den - den * other.num;
	den *= other.den;
	standardize();
	return *this;
}

Fraction & Fraction::operator*= (const Fraction & other)
{
	num *= other.num;
	den *= other.den;
	standardize();
	return *this;
}

Fraction & Fraction::operator/= (const Fraction & other)
{
	num *= other.den;
	den *= other.num;
	standardize();
	return *this;
}

// ARITHMETICAL OPERATORS

Fraction Fraction::operator-() const
{
	std::vector < int > temp = { -num, den };
	return Fraction(temp);
}

Fraction operator+ (const Fraction & lhs, const Fraction & rhs)
{
	return static_cast <Fraction> (lhs) += rhs;
}

Fraction operator- (const Fraction & lhs, const Fraction & rhs)
{
	return static_cast <Fraction > (lhs) -= rhs;
}

Fraction operator* (const Fraction & lhs, const Fraction & rhs)
{
	return static_cast <Fraction> (lhs) *= rhs;
}

Fraction operator/ (const Fraction & lhs, const Fraction & rhs)
{
	return static_cast <Fraction> (lhs) /= rhs;
}

bool operator== (const Fraction & lhs, const Fraction & rhs)
{
	// the fraction is standardized at the start of every member function
	return (lhs.num == rhs.num) && (lhs.den == rhs.den);
}

bool operator>  (const Fraction & lhs, const Fraction & rhs)
{
	return (lhs.num * rhs.den > rhs.num * lhs.den);
}

bool operator!= (const Fraction & lhs, const Fraction & rhs)
{
	return !(lhs == rhs);
}

bool operator>= (const Fraction & lhs, const Fraction & rhs)
{
	return (lhs > rhs) || (lhs == rhs);
}

bool operator<= (const Fraction & lhs, const Fraction & rhs)
{
	return !(lhs > rhs);
}

bool operator<  (const Fraction & lhs, const Fraction & rhs)
{
	return !(lhs > rhs) && !(lhs == rhs);
}

// INCREMENT-DECREMENT

Fraction & Fraction::operator++()
{
	num += den;
	return *this;
}

Fraction & Fraction::operator--()
{
	num -= den;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction temp(*this);
	++(*this);

	return temp;
}

Fraction Fraction::operator--(int)
{
	Fraction temp(*this);
	--(*this);

	return temp;
}

Fraction::operator double() const
{
	double a = static_cast < double > (num);
	double b = static_cast < double > (den); 
	return a / b;
}

std::string Fraction::get()
{
	return std::to_string(num) + "/" + std::to_string(den);
}