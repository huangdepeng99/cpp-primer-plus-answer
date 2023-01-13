#include <iostream>
#include <cstring>
#include "Plorg.h"

Plorg::Plorg(const char * nm, int c) {
	std::strncpy(name, nm, Len - 1);
	name[Len] = '\0';
	ci = c;
}

void Plorg::setci(int c) {
	ci = c;	
}

void Plorg::show() const {
	std::cout << "name: " << name << std::endl;
	std::cout << "ci: " << ci << std::endl;
}
