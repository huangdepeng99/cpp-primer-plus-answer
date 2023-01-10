#include <iostream>
#include <iomanip>
#include "winei.h"

Wine::Wine()
// : std::string(), PairArray()
{ }

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
: std::string(l), years(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y))
{ }

Wine::Wine(const char * l, int y)
: std::string(l), years(y), PairArray(ArrayInt(y), ArrayInt(y))
{ }

void Wine::GetBottles() {
	using std::cin;
	using std::cout;
	using std::endl;
	
	// cout << "Enter " << *this << " data for " << years << "year(s):" << endl;
	cout << "Enter " << (const std::string &) *this << " data for " << years << " year(s):" << endl;
	// PairArray & r = *this;
	PairArray & r = (PairArray &) *this;
	for (int i = 0; i < years; ++ i) {
		cout << "Enter year: ";
		cin >> r.first()[i];
		cout << "Enter bottles for that year: ";
		cin >> r.second()[i];
	}
}

const std::string & Wine::Label() const {
	// return *this;
	return (const std::string &) *this;
}

int Wine::sum() const {
	// const PairArray & r = *this;
	const PairArray & r = (const PairArray &) *this;
	return r.second().sum();
}

void Wine::Show() const {
	using std::cout;
	using std::endl;
	using std::setw;
	
	std::ios_base::fmtflags ff = cout.flags();
	char fillch = cout.fill(' ');
	
	cout << "Wine: " << (const std::string &) *this << endl
		 << setw(8) << ' ' << "Year" << setw(4) << ' ' << "Bottles" << endl;
	// const PairArray & r = *this;
	const PairArray & r = (const PairArray &) *this;
	cout << std::left;
	for (int i = 0; i < years; ++ i) {
		cout << setw(8) << ' ' << setw(4) << r.first()[i]
			 << setw(4) << ' ' << r.second()[i]
			 << endl;
	}
	
	cout.flags(ff);
	cout.fill(fillch);
}
