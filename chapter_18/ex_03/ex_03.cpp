#include <iostream>

using namespace std;

long double sum_value() { return 0.0; }

template< typename T, typename... Args >
long double sum_value(const T & val, const Args &... args) {
	return val + sum_value(args...);
}

int main(void) {
	cout << sum_value() << endl;
	cout << sum_value(3.14) << endl;
	cout << sum_value(3.14, 17, 'A') << endl;
	
	return 0;
}
