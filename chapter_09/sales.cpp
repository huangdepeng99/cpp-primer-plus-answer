#include <iostream>
#include <cstdlib>
#include "sales.h"

namespace SALES {
	void setSales(Sales & s, const double ar[], int n) {
		if (n <= 0)
			return;
		int m = n >= QUARTERS ? QUARTERS : n;
		s.average = 0.0;
		s.max = ar[0];
		s.min = ar[0];
		for (int i = 0; i < m; ++ i) {
			s.sales[i] = ar[i];
			s.average += ar[i];
			if (ar[i] > s.max)
				s.max = ar[i];
			if (ar[i] < s.min)
				s.min = ar[i];
		}
		s.average /= m;
		for (int i = m; i < QUARTERS; ++ i)
			s.sales[i] = 0.0;
	}
	
	void setSales(Sales & s) {
		using std::cin;
		using std::cout;
		using std::endl;
		cout << "Please enter the sales for four quarters: " << endl;
		for (int i = 0; i < QUARTERS; ++ i) {
			cout << "#" << i + 1 << ": ";
			cin >> s.sales[i];
			while (!cin) {
				if (cin.eof()) {
					cout << endl;
					std::cerr << "Eof-Of-File reached." << endl;
					std::exit(EXIT_FAILURE);
				} else if (cin.fail()) {
					cin.clear();
					while (cin.get() != '\n')
						;
				} else {	// cin.bad()
					std::cerr << "Input terminated for unkonwn reason." << endl;
					std::exit(EXIT_FAILURE);
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
	}
	
	void showSales(const Sales & s) {
		using std::cout;
		using std::endl;
		cout << "sales: ";
		for (int i = 0; i < QUARTERS; ++ i)
			cout << s.sales[i] << " ";
		cout << endl;
		cout << "average: " << s.average << endl;
		cout << "max: " << s.max << endl;
		cout << "min: " << s.min << endl;
	}
}
