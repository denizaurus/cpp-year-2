#include "A_header.hpp"
#include <format>

double Polygon::perimeter()
{
	double p = 0;
	size_t s = std::size(dots);

	for (auto i = 0U; i < s; ++i)
	{

		p += std::sqrt(
			std::pow((dots[i].first - dots[(i + 1) % s].first), 2) +
			std::pow((dots[i].second - dots[(i + 1) % s].second), 2)
		);
	}

	return p;
}

double Polygon::area()
{
	double a = 0;
	size_t s = std::size(dots);
	
	for (auto i = 0U; i < s; ++i)
	{
		a +=  dots[i].first * dots[(i + 1) % s].second
			- dots[i].second * dots[(i + 1) % s].first;
	}
	return abs(a/2);
}

double Rectangle::area()
{
	double a = std::sqrt(
		std::pow((dots[0].first - dots[1].first), 2) +
		std::pow((dots[0].second - dots[1].second), 2)
	);

	double b = std::sqrt(
		std::pow((dots[1].first - dots[2].first), 2) +
		std::pow((dots[1].second - dots[2].second), 2)
	);

	return a * b;
}

double Square::area()
{
	double a = 
		std::pow((dots[0].first - dots[1].first), 2) +
		std::pow((dots[0].second - dots[1].second), 2);

	return a;
}

void Polygon::print()
{
	std::cout <<
		"Polygon" << std::endl << "Dots:" << std::endl;

	for (point dot : dots)
	{
		std::cout << std::format("( {}, {} )", dot.first, dot.second) << " " ;
	}

	std::cout <<
		"\nSize: " << std::size(dots) << std::endl <<
		"Perimeter: " << perimeter() << std::endl <<
		"Area: " << area() << std::endl << std::endl;
}

void Ellipse::print()
{
	std::cout <<
		"Ellipse" << std::endl <<
		"Center: " << std::format("( {}, {} )", m_center.first, m_center.second) << std::endl <<
		"Semi-major: " << m_a << std::endl << 
		"Semi-minor: " << m_b << std::endl <<
		"Perimeter: " << perimeter() << std::endl <<
		"Area: " << area() << std::endl << std::endl;
}

void Circle::print()
{
	std::cout <<
		"Circle" << std::endl <<
		"Center: " << std::format("( {}, {} )", m_center.first, m_center.second) << std::endl <<
		"Radius: " << m_a << std::endl <<
		"Perimeter: " << perimeter() << std::endl <<
		"Area: " << area() << std::endl << std::endl;
}