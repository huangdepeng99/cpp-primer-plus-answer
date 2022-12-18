#include <iostream>
#include "complex0.h"

int main(void) {
	using std::cin;
	using std::cout;
	using std::endl;
	using COMPLEX::Complex;
	
	Complex a(3.0, 4.0);
	Complex c;
	cout << "Please enter a complex number (q to quit):" << endl;
	while (cin >> c) {
		cout << "c is " << c << endl;
		cout << "complex conjugate is " << ~c << endl;
		cout << "a is " << a << endl;
		cout << "a + c is " << a + c << endl;
		cout << "a - c is " << a - c << endl;
		cout << "a * c is " << a * c << endl;
		cout << "2 * c is " << 2 * c << endl;
		cout << "Please enter a complex number (q to quit):" << endl;
	}
	cout << "Done!" << endl;
	
	return 0;
}
