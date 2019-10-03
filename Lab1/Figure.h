#pragma once
class Figure {
public:
	virtual void reflection() {};
	virtual void output() {};
	virtual Figure* inversion() {
		return new Figure;
	};
};