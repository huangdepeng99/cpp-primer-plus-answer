#include <iostream>

using namespace std;

const double ONE_HUNDRED_KM_TO_MILE = 62.14;
const double GALLON_TO_LITRE = 3.785;

int main(void) {
	double european_method;
	cout << "Please enter the fuel consumption of the car using the European method:\n";
	cin >> european_method;
	double american_method = ONE_HUNDRED_KM_TO_MILE / (european_method / GALLON_TO_LITRE);
	cout << "The fuel consumption of the car in the American method is\n"
		 << american_method << "mpg" << endl;
	
	return 0;
}
