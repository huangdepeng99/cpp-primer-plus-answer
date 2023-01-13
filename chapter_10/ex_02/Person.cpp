#include <iostream>
#include <cstring>
#include "Person.h"

Person::Person(const std::string & ln, const char * fn) {
	lname = ln;
	std::strncpy(fname, fn, LIMIT - 1);
	fname[LIMIT] = '\0';
}

void Person::Show() const {
	std::cout << fname << " " << lname << std::endl;
}

void Person::FormalShow() const {
	std::cout << lname << ", " << fname << std::endl;
}
