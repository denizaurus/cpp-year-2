#pragma once
#include <iostream>
#include <string>
#include <vector>

class Fraction
{
public: 

	Fraction();
	Fraction(int);
	Fraction(std::string);

// OPERATORS

	friend std::ostream & operator<< (std::ostream &, const Fraction &);
	friend std::istream & operator>> (std::istream &, Fraction &);

	Fraction & operator+= (const Fraction &);
	Fraction & operator-= (const Fraction &);
	Fraction & operator*= (const Fraction &);
	Fraction & operator/= (const Fraction &);

	Fraction & operator++ ();
	Fraction & operator-- ();
	Fraction operator++(int);
	Fraction operator--(int);

	friend Fraction operator+ (const Fraction &, const Fraction &);
	friend Fraction operator- (const Fraction &, const Fraction &);
	friend Fraction operator* (const Fraction &, const Fraction &);
	friend Fraction operator/ (const Fraction &, const Fraction &);

	Fraction operator-() const;

	explicit operator double() const;

	friend bool operator== (const Fraction &, const Fraction &);
	friend bool operator!= (const Fraction &, const Fraction &);
	friend bool operator>  (const Fraction &, const Fraction &);
	friend bool operator<  (const Fraction &, const Fraction &);
	friend bool operator>= (const Fraction &, const Fraction &);
	friend bool operator<= (const Fraction &, const Fraction &);

// MEMBER FUNCTIONS

	void standardize();	
	std::string get(); // analogous to __repr__ in py

private:

	int num;
	int den;
	Fraction(std::vector < int >);

};