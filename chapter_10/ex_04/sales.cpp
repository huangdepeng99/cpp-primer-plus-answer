#include <iostream>
#include <cstdlib>
#include "sales.h"

namespace SALES {
	Sales::Sales() {
		for (int i = 0; i < QUARTERS; ++ i)
			sales[i] = 0.0;
		average = max = min = 0.0;
	}
	
	Sales::Sales(const double ar[], int n) {
		if (n <= 0)
			return;
		int m = n >= QUARTERS ? QUARTERS : n;
		average = 0.0;
		max = ar[0];
		min = ar[0];
		for (int i = 0; i < m; ++ i) {
			sales[i] = ar[i];
			average += ar[i];
			if (ar[i] > max)
				max = ar[i];
			if (ar[i] < min)
				min = ar[i];
		}
		average /= m;
		for (int i = m; i < QUARTERS; ++ i)
			sales[i] = 0.0;
	}
	
	void Sales::setSales() {
		using std::cin;
		using std::cout;
		using std::endl;
		Sales s;
		cout << "Please enter the sales for four quarters: " << endl;
		for (int i = 0; i < QUARTERS; ++ i) {
			cout << "#" << i + 1 << ": ";
			cin >> s.sales[i];
			while (!cin.good()) {
				if (cin.eof()) {
					std::cerr << endl;
					std::cerr << "Eof-Of-File reached." << endl;
					std::exit(EXIT_FAILURE);
				} else if (cin.bad()) {
					std::cerr << endl;
					std::cerr << "Input terminated for unkonwn reason." << endl;
					std::exit(EXIT_FAILURE);
				} else {	// cin.fail()
					cin.clear();
					while (cin.get() != '\n')
						;
				}
				cout << "Bad input! Please enter an number: ";
				cin >> s.sales[i];
			}
			while (cin.get() != '\n')
				;
		}
		s.average = 0.0;
		s.max = s.sales[0];
		s.min = s.sales[0];
		for (int i = 0; i < QUARTERS; ++ i) {
			s.average += s.sales[i];
			if (s.sales[i] > s.max)
				s.max = s.sales[i];
			if (s.sales[i] < s.min)
				s.min = s.sales[i];
		}
		s.average /= QUARTERS;
		*this = s;
	}
	
	void Sales::showSales() const {
		using std::cout;
		using std::endl;
		using std::ios_base;
		ios_base::fmtflags ff = cout.setf(ios_base::fixed, ios_base::floatfield);
		std::streamsize prec = cout.precision(2);
		
		cout << "sales: ";
		for (int i = 0; i < QUARTERS; ++ i)
			cout << sales[i] << " ";
		cout << endl;
		cout << "average: " << average << endl;
		cout << "max: " << max << endl;
		cout << "min: " << min << endl;
		
		cout.flags(ff);
		cout.precision(prec);
	}
}
