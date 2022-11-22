#include <iostream>
#include <cstddef>	// for size_t

using namespace std;

const int Max = 5;

double *fill_array(double *begin, double *end) {
	double *p;
	int i;
    for (p = begin, i = 1; p != end; ++ p, ++ i) {
        cout << "Enter value #" << i << ": ";
		double temp;
        cin >> temp;
        if (!cin) {
			cin.clear();
            while (cin.get() != '\n')
				;
			cout << "Bad input; input process terminated." << endl;
			break;
        } else if (temp < 0)
			break;
		*p = temp;
    }
	
    return p;
}

void show_array(const double *begin, const double *end) {
	const double *p;
	int i;
    for (p = begin, i = 1; p != end; ++ p, ++ i) {
        cout << "Property #" << i << ": $";
        cout << *p << endl;
    }
}

void revalue(double r, double *begin, double *end) {
    for (double *p = begin; p != end; ++ p)
        *p *= r;
}

int main(void) {
    double properties[Max];
	
    double *end = fill_array(properties, properties + Max);
    show_array(properties, end);
	size_t size = end - properties;
    if (size > 0) {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor)) {
			cin.clear();
			while (cin.get() != '\n')
				;
			cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, end);
        show_array(properties, end);
    }
    cout << "Done.\n";
	
    return 0;
}
