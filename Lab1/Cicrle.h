#pragma once
#include <cmath>
#include "Figure.h"
#include "Line.h"
#include "Point.h"
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