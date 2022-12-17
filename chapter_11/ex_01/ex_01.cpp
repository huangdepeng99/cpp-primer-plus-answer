#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "vect.h"

int main(void) {
    using std::cout;
	using std::cerr;
	using std::endl;
	using std::cin;
    using VECTOR::Vector;
	
	std::string filename;
	cout << "Please enter name of data file: ";
	std::getline(cin, filename);
	std::ofstream fout;
	fout.open(filename);
	if(!fout.is_open()) {
		cerr << "Could not open the file " << filename << endl;
		cerr << "Program terminating." << endl;
		std::exit(EXIT_FAILURE);
	}
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
		fout << "Target Distance: " << target << ", Step Size: " << dstep << endl;
		
		fout << steps << ": " << result << endl;
        while (result.magval() < target) {
            direction = std::rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
			steps++;
			fout << steps << ": " << result << endl;
        }
        cout << "After " << steps << " steps, the subject "
            "has the following location:" << endl;
        cout << result << endl;
        fout << "After " << steps << " steps, the subject "
            "has the following location:" << endl;
        fout << result << endl;
        result.polar_mode();
        cout << "or" << endl << result << endl;
        fout << "or" << endl << result << endl;
        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;
        fout << "Average outward distance per step = "
            << result.magval() / steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!" << endl;
	fout.close();
	
    return 0;
}
