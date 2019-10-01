#pragma once
#include "Figure.h"
#include "Line.h"
class Point : public Figure {
public:
	double x, y;
	Point(double x, double y);
		Point  reflection(Line some);

};