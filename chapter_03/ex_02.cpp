#include <iostream>

using namespace std;

const int FEET_TO_INCHES = 12;
const double INCHES_TO_METERS = 0.0254;
const double KILOGRAMS_TO_POUNTS = 2.2;

int main(void) {
	int feet, inches;
	cout << "Please enter your height in feet and inches "
			"(for example, 5 7 means 5 feet and 7 inches): \n";
	cin >> feet >> inches;
	double pounds;
	cout << "Please enter your weight in pounds: \n";
	cin >> pounds;
	
	double height = (feet * FEET_TO_INCHES + inches) * INCHES_TO_METERS;
	double weight = pounds / KILOGRAMS_TO_POUNTS;
	double bmi = weight / (height * height);
	cout << "Your BMI (Body Mass Index): " << bmi << endl;
	
	return 0;
}
