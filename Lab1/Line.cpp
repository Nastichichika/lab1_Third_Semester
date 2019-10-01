#include "Line.h"

Line::Line(double k, double b) : k(k), b(b) {}
Line Line::reflection(Line fig2) {
	double tg = abs((k - fig2.k) / (1 + k*fig2.k));
	double newk = (tg + k) / (1 - k*tg);
	double curx = (b - fig2.b) / (fig2.k - k);
	double cury = k*curx + b;
	double newb = cury - curx*newk;
	Line result(newk, newb);
	return result;
}
void Line::output() {
	std::cout << k << "x";
	if (b < 0) std::cout << b;
	else std::cout << "+" << b;
}
void Line::inversion(Circle fig) {
	if (pow(x0 - fig.x0, 2) + pow(y0 - fig.y0, 2) == pow(fig.radius, 2))
}