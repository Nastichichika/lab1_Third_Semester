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
Figure* Line::inversion(Circle fig) {
	if (k * fig.x0 + b == fig.y0) return new Line(k, b);
	else {
		int y1 = 0;
		int x1 = (y1 - b) / k;
		Point* point = new Point(x1, y1);
		point = point->inversion(fig);
		//
		int x2 = 0;
		int y2 = k*x2 + b;
		Point* point2 = new Point(x2, y2);
		point = point2->inversion(fig);

	}
}