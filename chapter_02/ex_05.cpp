#include <iostream>

using namespace std;

inline double celsius_to_fahrenheit(double cel) {
	return cel * 1.8 + 32.0;
}

int main(void) {
	double cel;
	cout << "Please enter a Celsius value: ";
	cin >> cel;
	cout << cel << " degrees Celsius is " << celsius_to_fahrenheit(cel)
		 << " degrees Fahrenheit." << endl;
	
	return 0;
}
