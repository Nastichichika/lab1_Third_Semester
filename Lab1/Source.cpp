#include <iostream> 
#include <vector> 
#include <cmath>
#include "Graph.h"
#include "Tree.h"
#include "NodeTree.h"
#include "ListNode.h"
using namespace std;

class Circle {
public:
	double x0, y0;
	double radius;
	Circle(double x0, double y0, double radius) {
		this->radius = radius;
		this->x0 = x0;
		this->y0 = y0;
	}
	Circle(double radius) {
		this->radius = radius;
		this->x0 = 0;
		this->y0 = 0;
	}
	void inversion(Circle fig) {
		double newx = x0 + ((radius*radius)*(x0 - fig.x0)) / ((x0 - fig.x0)*(x0 - fig.x0) + (y0 - fig.y0)*(y0 - fig.y0));
		double newy = y0 + ((radius*radius)*(y0 - fig.y0)) / ((x0 - fig.x0)*(x0 - fig.x0) + (y0 - fig.y0)*(y0 - fig.y0));

	}
};

class Line {
public:
	double k, b;

	Line(double k, double b) {
		this->k = k;
		this->b = b;
	}
	Circle reflection(Circle fig2) {
		double newk = (-1) / k;
		double newb = fig2.y0 - fig2.x0*newk;
		double perx = (b - newb) / (newk - k);
		double pery = newk*perx + newb;
		double rezx = 2 * perx - fig2.x0;
		double rezy = 2 * pery - fig2.y0;
		Circle result(rezx, rezy, fig2.radius);
		return result;
	}
	Line reflection(Line fig2) {
		double tg = abs((k - fig2.k) / (1 + k*fig2.k));
		double newk = (tg + k) / (1 - k*tg);
		double curx = (b - fig2.b) / (fig2.k - k);
		double cury = k*curx + b;
		double newb = cury - curx*newk;
		Line result(newk, newb);
		return result;
	}
};

class Point {
	double x, y;
public:
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	void reflectionPoint(Line some) {

	}

};

int main() {
	/*Graph<int> abc = Graph<int>();
	abc.addVertex(0);
	abc.addVertex(1);
	abc.addVertex(2);
	abc.addVertex(3);
	abc.addVertex(4);
	abc.addEdge(0, 1);
	abc.addEdge(2, 1);
	abc.addEdge(4, 1);
	abc.addEdge(2, 3);
	abc.PrintGraph();
	Tree<int>* bcd = abc.SpanningTree();
	bcd->Print();*/
	Tree<int> bcd = Tree<int>();
	bcd.addVertex(5, bcd.getRoot());
	bcd.addVertex(1, 5);
	bcd.addVertex(2, 5);
	bcd.addVertex(3, 5);
	bcd.addVertex(4, 5);
	bcd.addVertex(9, 4);
	bcd.Print();
	bcd.deleteVertex(5);
	bcd.Print();
	return 0;
}