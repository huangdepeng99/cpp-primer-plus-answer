#include <iostream>
#include "cow.h"

int main(void) {
	using std::cout;
	using std::endl;
	
	Cow *pc1 = new Cow("Tony Stark", "football", 116.5);
	pc1->ShowCow();
	
	Cow c2 = *pc1;
	cout << endl;
	c2.ShowCow();
	delete pc1;
	cout << endl;
	c2.ShowCow();
	
	Cow c3;
	c3 = Cow("Vincent", "basketball", 142.8);
	cout << endl;
	c3.ShowCow();
	
	return 0;
}
