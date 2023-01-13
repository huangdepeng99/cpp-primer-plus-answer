#include <iostream>
#include "Plorg.h"

int main(void) {
	using std::cout;
	using std::endl;
	Plorg p1;
	p1.show();
	p1.setci(100);
	cout << endl;
	p1.show();
	
	Plorg p2("AAA", 75);
	cout << endl;
	p2.show();
	
	return 0;
}
