#pragma once
#include <iostream>
#include <cmath>
#include "Figure.h"
class Line : public Figure{
public:
	double k, b;

	Line(double k, double b);
	Line reflection(Line fig2);
	void output();
};