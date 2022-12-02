#include <iostream>
#include <cstring>
#include <cstdlib>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc) {
	std::size_t size = std::strlen(name);
	if (size <= Len - 1) {
		std::strcpy(g.fullname, name);
	} else {
		std::strncpy(g.fullname, name, Len - 1);
		g.fullname[Len] = '\0';
	}
	g.handicap = hc;
}

int setgolf(golf & g) {
	using std::cin;
	using std::cout;
	using std::cerr;
	using std::endl;
	using std::exit;
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
	
	return 1;
}

void handicap(golf & g, int hc) {
	g.handicap = hc;
}

void showgolf(const golf & g) {
	std::cout << "full name: " << g.fullname << std::endl;
	std::cout << "handicap: " << g.handicap << std::endl;
}
