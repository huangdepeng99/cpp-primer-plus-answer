#include <iostream>
#include "Move.h"

Move::Move(double a, double b) {
	x = a;
	y = b;
}

void Move::showmove() const {
	using std::ios_base;
	using std::cout;
	using std::endl;
	ios_base::fmtflags ff = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(2);
	
	cout << "x = " << x << ", y = " << y << endl;
	
	cout.flags(ff);
	cout.precision(prec);
}

Move Move::add(const Move & m) const {
	double nx = x + m.x;
	double ny = y + m.y;
	Move nm(nx, ny);
	return nm;
}

void Move::reset(double a, double b) {
	x = a;
	y = b;
}
