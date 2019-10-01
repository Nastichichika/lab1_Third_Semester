#include "Cicrle.h"

Circle::Circle(double x0, double y0, double radius) : radius(radius), x0(x0), y0(y0) {}
Circle::Circle(double radius) : radius(radius), x0(0), y0(0) {}
Circle Circle::reflection(Line some) {
	Point temp = Point(x0, y0);
	Point temp2 = temp.reflection(some);
	Circle result(temp2.x, temp2.y, radius);
	return result;
}
void Circle::inversion(Circle fig) {
	double newx = x0 + ((radius*radius)*(x0 - fig.x0)) / ((x0 - fig.x0)*(x0 - fig.x0) + (y0 - fig.y0)*(y0 - fig.y0));
	double newy = y0 + ((radius*radius)*(y0 - fig.y0)) / ((x0 - fig.x0)*(x0 - fig.x0) + (y0 - fig.y0)*(y0 - fig.y0));

}
