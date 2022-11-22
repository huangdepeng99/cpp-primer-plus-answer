#include <iostream>

using namespace std;

unsigned long long factorial(int n) {
	if (n == 1)
		return 1;
	return n * factorial(n - 1);
}

int main(void) {
	int n;
	while (cin >> n) {
		if (n < 0) {
			cout << "Please enter a non negative integer" << endl;
		} else if (n == 0) {
			cout << "0! = 1"<< endl;
		} else {
			cout << n  << "! = " << factorial(n) << endl;
		}
	}
	
	return 0;
}
