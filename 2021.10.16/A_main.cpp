#include "A_header.hpp"

int main()
{
	point a = { 0.0, 0.0 };
	point b = { 1.0, 1.0 };
	point c = { 1.0, 0.0 };
	point d = { 0.0, 1.0 };
	point e = { -0.5, 2.48 };

	std::vector < point > square_c = { a, c, b, d };
	std::vector < point > triangle_c = { a, b, c };
	std::vector < point > polygon_c = { a, c, b, d, e };

	Square sq(square_c);
	Triangle tri(triangle_c);
	Polygon p(polygon_c);
	Ellipse el(a, 1, 2);
	Circle circ(a, 1);

	sq.print();
	tri.print();
	p.print();
	el.print();
	circ.print();

	system("pause");
	return EXIT_SUCCESS;
}