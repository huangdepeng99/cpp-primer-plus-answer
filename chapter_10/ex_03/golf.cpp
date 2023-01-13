#include <iostream>
#include <cstring>
#include <cstdlib>
#include "golf.h"

golf::golf(const char * name, int hc) {
	std::size_t size = std::strlen(name);
	if (size <= Len - 1) {
		std::strcpy(fullname, name);
	} else {
		std::strncpy(fullname, name, Len - 1);
		fullname[Len] = '\0';
	}
	handicap = hc;
}

int golf::setgolf() {
	using std::cin;
	using std::cout;
	using std::cerr;
	using std::endl;
	using std::exit;
	golf g;
	cout << "Please enter your full name: ";
	cin.get(g.fullname, Len);
	if (!cin.good()) {
		if (cin.eof()) {
			cerr << endl;
			cerr << "End-Of-File reached." << endl;
			exit(EXIT_FAILURE);
		} else if (cin.bad()) {
			cerr << endl;
			cerr << "Input terminated for unknown reason." << endl;
			exit(EXIT_FAILURE);
		} else {	// cin.fail()
			cin.clear();
			cin.get();
			return 0;
		}
	}
	while (cin.get() != '\n')
		;
	
	cout << "Please enter your handicap: ";
	cin >> g.handicap;
	while (!cin.good()) {
		if (cin.eof()) {
			cerr << endl;
			cerr << "End-Of-File reached." << endl;
			exit(EXIT_FAILURE);
		} else if (cin.bad()) {
			cerr << endl;
			cerr << "Input terminated for unknown reason." << endl;
			exit(EXIT_FAILURE);
		} else {	// cin.fail()
			cin.clear();
			while (cin.get() != '\n')
				;
		}
		cout << "Bad input! Please re-enter: ";
		cin  >> g.handicap;
	}
	while (cin.get() != '\n')
		;
	
	*this = g;
	
	return 1;
}

void golf::sethandicap(int hc) {
	handicap = hc;
}

void golf::showgolf() const {
	std::cout << "full name: " << fullname << std::endl;
	std::cout << "handicap: " << handicap << std::endl;
}
