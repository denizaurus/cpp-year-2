#include "A_header.hpp"

int main()
{
	using point = std::pair < double, double >;
	using point_v = std::vector < point >;

	point a = { 0.0, 0.0 };
	point b = { 1.0, 1.0 };
	point c = { 1.0, 0.0 };
	point d = { 0.0, 1.0 };
	point e = { -0.5, 2.48 };

	point_v square_c = { a, c, b, d };
	point_v triangle_c = { a, b, c };
	point_v polygon_c = { a, c, b, d, e };

	Square sq(square_c);
	Triangle tri(triangle_c);
	Polygon p(polygon_c);
	Ellipse el(a, 1, 2);
	Circle circ(a, 1);

	std::vector < Shape * > shapes = { &sq, &tri, &p, &el, &circ };

	for (Shape * shape : shapes)
	{
		shape->print();
	}

	system("pause");
	return EXIT_SUCCESS;
}