#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow() {
	name[0] = '\0';
	hobby = nullptr;
	weight = 0.0;
}

Cow::Cow(const char * nm, const char * ho, double wt) {
	std::strncpy(name, nm, 19);
	name[20] = '\0';
	hobby = new char[std::strlen(ho) + 1];
	std::strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow & c) {
	std::strcpy(name, c.name);
	hobby = new char[std::strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow() {
	delete [] hobby;
}

Cow & Cow::operator=(const Cow & c) {
	if (this == &c)
		return *this;
	std::strcpy(name, c.name);
	delete [] hobby;
	hobby = new char[std::strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const {
	using std::cout;
	using std::endl;
	using std::ios_base;
	ios_base::fmtflags ff = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(2);
	
	cout << "name: " << name << endl
		 << "hobby: " << hobby << endl
		 << "weight: " << weight << endl;
	
	cout.flags(ff);
	cout.precision(prec);
}
