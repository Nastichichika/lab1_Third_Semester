#pragma once
#include <cmath>
#include "Figure.h"
class Line : Figure{
public:
	double k, b;

	Line(double k, double b);
	Line reflection(Line fig2);
};