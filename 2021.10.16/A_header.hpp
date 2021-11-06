#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <numbers>

class Shape
{
public:

	using point = std::pair < double, double >;
	using point_v = std::vector < point >;

	virtual double perimeter() = 0;
	virtual double area() = 0;
	virtual void print() = 0;

	virtual ~Shape() = default;

	const static inline double pi = std::numbers::pi;
};


class Polygon : public Shape
{
public:
	explicit Polygon(const point_v & d) : dots(d) {};
	virtual ~Polygon() = default;

	virtual double perimeter() override final;
	virtual double area() override;
	virtual void print();

protected:
	point_v dots;
	double distance(point &, point &);
};


class Triangle : public Polygon
{
public:
	Triangle(const point_v & d) : Polygon(d) {};
};


class Quadragle : public Polygon
{
public:
	Quadragle(const point_v & d) : Polygon(d) {};
	virtual ~Quadragle() = default;
};


class Rectangle : public Quadragle
{
public:
	Rectangle(const point_v & d) : Quadragle(d) {};
	virtual ~Rectangle() = default;

	virtual double area() override
	{
		return distance(dots[0], dots[1]) * distance(dots[1], dots[2]);
	}
};


class Square : public Rectangle
{
public:
	Square(const point_v & d) : Rectangle(d) {};

	double area() override
	{
		return std::pow(distance(dots[0], dots[1]), 2);
	}
};


class Ellipse : public Shape
{
public:
	Ellipse(const point & c, const double a, const double b) : m_center(c), m_a(a), m_b(b) {};
	virtual ~Ellipse() = default;

	virtual double perimeter() override
	{
		return 4.0 * (pi * m_a * m_b + std::pow(m_a - m_b, 2)) / (m_a + m_b);
	};
	virtual double area() override { return pi * m_a * m_b; };
	virtual void print();

protected:
	point m_center;
	double m_a;
	double m_b;

};


class Circle : public Ellipse
{
public:
	Circle(const point & c, const double r) : Ellipse(c, r, r) {};

	double perimeter() override { return 2.0 * pi * m_a; };
	double area() override { return pi * m_a * m_a; };
	void print();
};