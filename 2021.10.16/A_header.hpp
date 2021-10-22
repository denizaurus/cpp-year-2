#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <iostream>


using point = std::pair< double, double > ;


class Shape
{
public:

	virtual double perimeter() = 0;
	virtual double area() = 0;
	virtual void print() = 0;

	virtual ~Shape() = default;
};


class Polygon : public Shape
{
public:
	explicit Polygon(std::vector < point > d) : dots(d) {};
	virtual ~Polygon() = default;

	virtual double perimeter() final;
	virtual double area();
	virtual void print();

protected:
	std::vector < point > dots;
};


class Triangle : public Polygon
{
public:
	Triangle(std::vector < point > d) : Polygon(d) {};
};


class Quadragle : public Polygon
{
public:
	Quadragle(std::vector < point > d) : Polygon(d) {};
	virtual ~Quadragle() = default;
};


class Rectangle : public Quadragle
{
public:
	Rectangle(std::vector < point > d) : Quadragle(d) {};
	virtual ~Rectangle() = default;

	virtual double area();
};


class Square : public Rectangle
{
public:
	Square(std::vector < point > d) : Rectangle(d) {};

	double area();
};


class Ellipse : public Shape
{
public:
	Ellipse(point c, double a, double b) : m_center(c), m_a(a), m_b(b) {};
	virtual ~Ellipse() = default;

	virtual double perimeter() 
	{
		return 4 * (pi * m_a * m_b + std::pow(m_a - m_b, 2)) / (m_a + m_b);
	};
	virtual double area() { return pi * m_a * m_b; };
	virtual void print();

protected:
	point m_center;
	double m_a;
	double m_b;

	const static inline double pi = 3.1415926;
};


class Circle : public Ellipse
{
public:
	Circle(point c, double r) : Ellipse(c, r, 0) {};

	double perimeter() { return 2 * pi * m_a; };
	double area() { return pi * m_a * m_a; };
	void print();
};