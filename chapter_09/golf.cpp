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
	std::cout << "Please enter your full name: ";
	cin.get(g.fullname, Len);
	if (cin.eof()) {
		std::cout << std::endl;
		std::cerr << "End-Of-File reached." << std::endl;
		std::exit(EXIT_FAILURE);
	} else if (cin.fail()) {
		cin.clear();
		cin.get();
		return 0;
	} else if (cin.bad()) {
		std::cout << std::endl;
		std::cerr << "Input terminated for unknown reason." << std::endl;
		std::exit(EXIT_FAILURE);
	}
	while (cin.get() != '\n')
		;
	
	std::cout << "Please enter your handicap: ";
	(cin >> g.handicap).get();
	
	return 1;
}

void handicap(golf & g, int hc) {
	g.handicap = hc;
}

void showgolf(const golf & g) {
	std::cout << "full name: " << g.fullname << std::endl;
	std::cout << "handicap: " << g.handicap << std::endl;
}
