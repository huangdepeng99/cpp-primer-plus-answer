#include <iostream>

using namespace std;

int main(void) {
	long double income;
	
	while (cin >> income && income >= 0) {
		long double tax = 0;
		if (income > 35000) {
			tax += (income - 35000) * 0.2;
			income = 35000;
		}
		
		if (15000 < income && income <= 35000) {
			tax += (income - 15000) * 0.15;
			income = 15000;
		}
		
		if (5000 < income && income <= 15000) {
			tax += (income - 5000) * 0.1;
			income = 5000;
		}
		cout << "tax = " << tax << endl;
	}
	
	return 0;
}
