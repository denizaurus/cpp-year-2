#pragma once
#include <iostream>
#include <string>
#include <vector>

class Fraction
{
public: 

	Fraction() : num(0), den(1) {};
	Fraction(int x) : num(x), den(1) {};
	Fraction(int, int);

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

	int get_numerator();
	int get_denominator();

	std::string get_print(); // analogous to __repr__ in py

private:

	int num;
	int den;

};