#include <iostream>

using namespace std;

inline double
light_years_to_astronomical_units(double ly) {
	return ly * 63240.0;
}

int main(void) {
	double ly;
	cout << "Enter the number of light years: ";
	cin >> ly;
	cout << ly << " light years = " << light_years_to_astronomical_units(ly)
		 << " astronomical units." << endl;
	
	return 0;
}
