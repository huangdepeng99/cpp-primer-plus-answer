#include <iostream>

using namespace std;

void repeat(char c, int t) {
	for (int i = 0; i < t; ++ i)
		cout << c;
}

const int FEET_TO_INCHES = 12;

int main(void) {
	int height;
	int times = 8;
	cout << "Please enter your height in inches: ";
	repeat('_', times);
	repeat('\b', times);
	cin >> height;
	int feet = height / FEET_TO_INCHES;
	int inches = height - feet * FEET_TO_INCHES;
	cout << "Your height in feet and inches: " << feet << " feet and "
		 << inches << " inches" << endl;
	
	return 0;
}
