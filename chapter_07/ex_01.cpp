#include <iostream>

using namespace std;

double harmonic_mean(double x, double y) {
	return 2.0 * x * y / (x + y);
}

int main(void) {
	double a, b;
	while (cin >> a >> b && a != 0.0 && b != 0.0)
		cout << "The harmonic mean of " << a << " and " << b << " is "
			 << harmonic_mean(a, b) << endl;
	
	return 0;
}
