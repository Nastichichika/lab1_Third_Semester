#include "Point.h"

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}
Point Point::reflection(Line some) {
	Line normal(-1 / some.k, y - (-1 / some.k) * x);
	double tempx = ((y - (-1 / some.k) * x) - some.b) / (some.k - (-1 / some.k));
	double tempy = x * (-1 / some.k) + (y - (-1 / some.k) * x);
	return Point((2 * tempx - x), (2 * tempy - y));
}
