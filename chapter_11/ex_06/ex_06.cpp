#include <iostream>
#include "stonewt.h"

int main(void) {
	using std::cin;
	using std::cout;
	using std::endl;
	Stonewt as[6] = {
		Stonewt(97.0),
		Stonewt(12, 5.0),
		Stonewt(3, 7.0),
	};
	
	cout << "Please enter up to 3 pounds (press p to stop)" << endl;
	int idx;
	for (idx = 0; idx < 3; ++ idx) {
		cout << "#" << idx + 1 << endl;
		cout << "Please enter the pounds: ";
		double pounds;
		if (!(cin >> pounds))
			break;
		as[idx + 3] = Stonewt(pounds);
	}
	
	Stonewt maximum = as[0];
	Stonewt minimum = as[0];
	Stonewt eleven(11, 0.0);
	int counter = 0;
	for (int i = 0; i < idx + 3; ++ i) {
		if (as[i] > maximum)
			maximum = as[i];
		if (as[i] < minimum)
			minimum = as[i];
		if (as[i] >= eleven)
			++ counter;
	}
	
	cout << endl;
	cout << "maximum: " << endl;
	maximum.show_lbs();
	cout << "or" << endl;
	maximum.show_stn();
	
	cout << endl;
	cout << "minimum: " << endl;
	minimum.show_lbs();
	cout << "or" << endl;
	minimum.show_stn();
	
	cout << endl;
	cout << "There are " << counter << " elements greater than or equal to 11 stone" << endl;
	
	return 0;
}
