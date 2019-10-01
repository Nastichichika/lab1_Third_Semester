#pragma once
#include "Figure.h"
#include "Line.h"
#include "Cicrle.h"
class Point : public Figure {
public:
	double x, y;
	Point(double x, double y);
	Point  reflection(Line some);
	void output();
	void inversion(Circle fig);
};