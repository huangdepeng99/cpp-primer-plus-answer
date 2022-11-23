#include <iostream>
#include <cstddef>	// for size_t

using namespace std;

typedef double (*pf_t)(double, double);

double add(double x, double y) {
	return x + y;	
}

double average(double x, double y) {
	return (x + y) / 2.0;
}

pf_t apf[] = {
	add,
	average,
};

const char *msg[] = {
	"sum: ",
	"average: ",
};

double calculate(double x, double y, pf_t pf) {
	return pf(x, y);
}

int main(void) {
	size_t size = sizeof(apf) / sizeof(pf_t);
	double x, y;
	cout << "Enter two numbers (enter non number to exit): ";
	while (cin >> x >> y) {
		for (int i = 0; i < size; ++ i)
			cout << msg[i] << calculate(x, y, apf[i]) << endl;
		cout << "Next two numbers: ";
	}
	
	return 0;
}
