#pragma once
#include <cmath>
class Point;
#include "Point.h"
#include "Figure.h"
class Circle : public Figure {
public:
	double x0, y0;
	double radius;
	Circle(double x0, double y0, double radius);
	Circle(double radius);
	Circle reflection(Line a);
	void inversion(Circle fig);
	void output();
};