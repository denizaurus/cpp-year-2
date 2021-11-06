#include "B_header.hpp"
#include <numeric>
#include <exception>

namespace tools
{
	int sign(int x)
	{
		return (x >= 0) ? 1 : -1;
	}
}

Fraction::Fraction(int n, int d) : num(n), den(d) 
{ 
	if (den == 0)
	{
		throw std::invalid_argument("Division by zero undefined.");
	}
	standardize(); 
};

// INPUT-OUTPUT OPERATORS

std::ostream & operator<< (std::ostream & stream, const Fraction & frac)
{
	stream << frac.num << "/" << frac.den << std::endl;
	return stream;
}

std::istream & operator>> (std::istream & stream, Fraction & frac)
{
	char t;

	stream >> frac.num;
	stream >> t;
	stream >> frac.den; // format: NUM whitespace / whitespace DEN

	if (frac.den == 0)
	{
		throw std::invalid_argument("Division by zero undefined.");
	}

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
	return Fraction( -num, den );
}

Fraction operator+ (const Fraction & lhs, const Fraction & rhs)
{
	return Fraction(lhs) += rhs;
}

Fraction operator- (const Fraction & lhs, const Fraction & rhs)
{
	return Fraction(lhs) -= rhs;
}

Fraction operator* (const Fraction & lhs, const Fraction & rhs)
{
	return Fraction(lhs) *= rhs;
}

Fraction operator/ (const Fraction & lhs, const Fraction & rhs)
{
	return Fraction(lhs) /= rhs;
}

// LOGICAL OPERATORS

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

// MEMBER FUNCTIONS

void Fraction::standardize()
{
	int gcd = std::gcd(num, den);

	num /= gcd;
	den /= gcd;

	num *= tools::sign(den);
	den *= tools::sign(den);
}

int Fraction::get_numerator()
{
	return num;
}

int Fraction::get_denominator()
{
	return den;
}

std::string Fraction::get_print()
{
	return std::to_string(num) + "/" + std::to_string(den);
}