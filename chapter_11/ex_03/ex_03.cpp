#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"

int main(void) {
    using std::cout;
	using std::endl;
	using std::cin;
    using VECTOR::Vector;
	
	std::srand(std::time(NULL));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
	unsigned long n;
	cout << "Please enter the number of tests: ";
	cin >> n;
	unsigned long maximum;
	unsigned long minimum;
	double sum = 0.0;
	unsigned long i;
    for (i = 0; i < n; ++ i) {
		cout << "Enter target distance (q to quit): ";
		if (!(cin >> target))
			break;
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
		
        while (result.magval() < target) {
            direction = std::rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
			steps++;
        }

		if (i == 0) {
			maximum = steps;
			minimum = steps;
		} else {
			if (steps > maximum)
				maximum = steps;
			if (steps < minimum)
				minimum = steps;
		}
		sum += steps;
		
        steps = 0;
        result.reset(0.0, 0.0);
    }
	if (i != 0) {
		cout << "maximum: " << maximum << endl;
		cout << "minimum: " << minimum << endl;
		cout << "average: " << sum / i << endl;
	}
    cout << "Bye!" << endl;
	
    return 0;
}
