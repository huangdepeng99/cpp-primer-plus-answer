#include <iostream>
#include <sstream>
#include <cmath> // or math.h, unix users may need -lm flag
#include "exc_mean.h"

double hmean(double a, double b) {
    if (a == -b) {
		std::ostringstream oss;
		oss << "hmean(" << a << ", " << b << "): "
			<< "invalid arguments: a = -b";
        throw bad_hmean(oss.str());
	}
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
    if (a < 0 || b < 0) {
		std::ostringstream oss;
		oss << "gmean(" << a << ", " << b << "): "
			<< "arguments should be >= 0";
        throw bad_gmean(oss.str());
	}
    return std::sqrt(a * b); 
}

int main(void) {
    using std::cin;
    using std::cout;
    using std::endl;
    
    double a, b;
	
    cout << "Enter two numbers: ";
    while (cin >> a >> b) {
        try {                  // start of try block
            double h = hmean(a, b);
			double g = gmean(a, b);
            cout << "Harmonic mean of " << a << " and " << b
                 << " is " << h << endl;
            cout << "Geometric mean of " << a << " and " << b
                 << " is " << g << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }	// end of try block
        catch (const bad_hmean & bh) {	// start of catch block
            cout << bh.what() << endl;
            cout << "Try again." << endl;
            continue;
        }
        catch (const bad_gmean & bg) {
            cout << bg.what() << endl;
            cout << "Sorry, you don\'t get to play any more." << endl;
            break;
        }	// end of catch block
    }
    cout << "Bye!" << endl;
    
    return 0;
}
