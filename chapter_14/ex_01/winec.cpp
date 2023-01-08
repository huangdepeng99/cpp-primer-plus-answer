#include <iostream>
#include <iomanip>
#include "winec.h"

Wine::Wine()
{ }

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
: label(l), years(y), pa(ArrayInt(yr, y), ArrayInt(bot, y))
{ }

Wine::Wine(const char * l, int y)
: label(l), years(y), pa(ArrayInt(y), ArrayInt(y))
{ }

void Wine::GetBottles() {
	using std::cin;
	using std::cout;
	using std::endl;
	
	cout << "Enter " << label << " data for " << years << "year(s):" << endl;
	for (int i = 0; i < years; ++ i) {
		cout << "Enter year: ";
		cin >> pa.first()[i];
		cout << "Enter bottles for that year: ";
		cin >> pa.second()[i];
	}
}

const std::string & Wine::Label() const {
	return label;
}

int Wine::sum() const {
	return pa.second().sum();
}

void Wine::Show() const {
	using std::cout;
	using std::endl;
	using std::setw;
	
	cout << "Wine: " << label << endl
		 << setw(8) << ' ' << "Year" << setw(4) << ' ' << "Bottles" << endl;
	for (int i = 0; i < years; ++ i) {
		cout << setw(8) << ' ' << pa.first()[i]
			 << setw(4) << ' ' << pa.second()[i]
			 << endl;
	}
}
