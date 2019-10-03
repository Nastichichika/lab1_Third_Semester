#include "Point.h"
Point::Point(double x, double y) : x(x), y(y) {}
Point Point::reflection(Line some) {
	Line normal(-1 / some.k, y - (-1 / some.k) * x);
	double tempx = ((y - (-1 / some.k) * x) - some.b) / (some.k - (-1 / some.k));
	double tempy = x * (-1 / some.k) + (y - (-1 / some.k) * x);
	return Point((2 * tempx - x), (2 * tempy - y));
}
void Point::output() {
	std::cout << x << " " << y;
}
Point* Point::inversion(Circle fig) {
	double newx = x + ((fig.radius*fig.radius)*(x - fig.x0)) / ((x - fig.x0)*(x - fig.x0) + (y - fig.y0)*(y - fig.y0));
	double newy = y + ((fig.radius*fig.radius)*(y - fig.y0)) / ((x - fig.x0)*(x - fig.x0) + (y - fig.y0)*(y - fig.y0));
	return new Point(newx, newy);
}