#include <format>
#include "A_header.hpp"

void Shape::print()
{
	std::cout << "Perimeter: " << perimeter() << std::endl
			  << "Area: "  << area() << std::endl << std::endl;
}

double Polygon::distance(point & p1, point & p2)
{
	double d = std::sqrt(
		std::pow((p1.first - p2.first), 2) +
		std::pow((p1.second - p2.second), 2));

	return d;
}

double Polygon::perimeter()
{
	auto p = 0.0;
	size_t s = std::size(dots);

	for (auto i = 0U; i < s; ++i)
	{
		p += distance(dots[i], dots[(i + 1) % s]);
	}
	return p;
}

double Polygon::area()
{
	auto a = 0.0;
	size_t s = std::size(dots);
	
	for (auto i = 0U; i < s; ++i)
	{
		a +=  dots[i].first * dots[(i + 1) % s].second
			- dots[i].second * dots[(i + 1) % s].first;
	}
	return std::abs(a / 2.0);
}

void Polygon::print()
{
	std::cout <<
		"Polygon" << std::endl << "Dots:" << std::endl;

	for (point & dot : dots)
	{ 
		std::cout << std::format("( {}, {} )", dot.first, dot.second) << " " ;
	}

	std::cout << "\nSize: " << std::size(dots) << std::endl;
	Shape::print();
}

void Ellipse::print()
{
	std::cout <<
		"Ellipse" << std::endl <<
		"Center: " << std::format("( {}, {} )", m_center.first, m_center.second) << std::endl <<
		"Semi-major: " << m_a << std::endl <<
		"Semi-minor: " << m_b << std::endl;
	Shape::print();
}

void Circle::print()
{
	std::cout <<
		"Circle" << std::endl <<
		"Center: " << std::format("( {}, {} )", m_center.first, m_center.second) << std::endl <<
		"Radius: " << m_a << std::endl;
	Shape::print();
		
}