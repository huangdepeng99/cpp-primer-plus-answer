#include <cstring>
#include "port.h"

Port::Port(const char * br, const char * st, int b) {
	brand = new char[std::strlen(br) + 1];
	std::strcpy(brand, br);
	std::strncpy(style, st, 19);
	style[19] = '\0';
	bottles = b;
}

Port::Port(const Port & p) {
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strncpy(style, p.style, 19);
	style[19] = '\0';
	bottles = p.bottles;
}

Port & Port::operator=(const Port & p) {
	if (this == &p)
		return *this;
	delete [] brand;
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strncpy(style, p.style, 19);
	style[19] = '\0';
	bottles = p.bottles;
	return *this;
}

Port & Port::operator+=(int b) {
	if (b < 0)
		std::cout << "The addend cannot be less than 0." << std::endl;
	else
		bottles += b;
	return *this;
}

Port & Port::operator-=(int b) {
	if (b < 0) {
		std::cout << "The subtrahend cannot be less than 0." << std::endl;
	} else if (b > bottles) {
		std::cout << "You can\'t subtract more than you have." << std::endl;
	} else {
		bottles -= b;
	}
	return *this;
}

void Port::Show() const {
	std::cout << "Brand: " << brand << std::endl
			  << "Kind: " << style << std::endl
			  << "Bottles: " << bottles << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Port & p) {
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}
