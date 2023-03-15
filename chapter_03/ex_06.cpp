#include <iostream>

using namespace std;

int main(void) {
	double driving_distance, amount_of_gasoline;
	cout << "Please enter the driving distance in miles: ";
	cin >> driving_distance;
	cout << "Please enter the amount of gasoline in gallons: ";
	cin >> amount_of_gasoline;
	cout << "The mileage of the car per gallon of gas is "
		 << driving_distance / amount_of_gasoline << "mpg"
		 << endl;
	
	return 0;
}
