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
    cout << "Enter target distance (q to quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
		
        while (result.magval() < target) {
            direction = std::rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
			steps++;
        }
        cout << "After " << steps << " steps, the subject "
            "has the following location:" << endl;
        cout << result << endl;
        result.polar_mode();
        cout << "or" << endl << result << endl;
        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!" << endl;
	
    return 0;
}
