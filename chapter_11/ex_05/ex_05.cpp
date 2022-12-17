#include <iostream>
#include "stonewt.h"

int main(void) {
	using std::cout;
	using std::endl;
	
	Stonewt sw1(56.7);
	cout << sw1 << endl;
	sw1.stn_mode();
	cout << sw1 << endl;
	
	cout << endl;
	Stonewt sw2(5, 9.0);
	cout << sw2 << endl;
	sw2.lbs_mode();
	cout << sw2 << endl;
	
	cout << endl;
	Stonewt total = sw1 + sw2;
	cout << total << endl;
	
	cout << endl;
	cout << sw2 - sw1 << endl;
	
	cout << endl;
	cout << sw1 * 2.0 << endl;

	cout << endl;
	cout << 10.0 * sw2 << endl;
	
	return 0;
}
