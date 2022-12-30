#include <cstring>
#include "cd.h"

// Cd::Formatting Cd::SetFormat() {
auto Cd::SetFormat() -> Formatting {
	using std::cout;
	using std::ios_base;
	
	Formatting f;
	f.ff = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.prec = cout.precision(2);
	
	return f;
}

void Cd::Restore(const Formatting & f) {
	using std::cout;

	cout.flags(f.ff);
	cout.precision(f.prec);
}

Cd::Cd(const char * s1, const char * s2, int n, double x) {
	performers = new char[std::strlen(s1) + 1];
	std::strcpy(performers, s1);
	label = new char[std::strlen(s2) + 1];
	std::strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d) {
	performers = new char[std::strlen(d.performers) + 1];
	std::strcpy(performers, d.performers);
	label = new char[std::strlen(d.label) + 1];
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd() {
	performers = nullptr;
	label = nullptr;
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd() {
	delete [] performers;
	delete [] label;
}

Cd & Cd::operator=(const Cd & d) {
	if (this == &d)
		return *this;
	delete [] performers;
	performers = new char[std::strlen(d.performers) + 1];
	std::strcpy(performers, d.performers);
	delete [] label;
	label = new char[std::strlen(d.label) + 1];
	std::strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

void Cd::Report() const {
	using std::cout;
	using std::endl;
	
	Formatting f = SetFormat();
	
	cout << "Performers: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Number of selections: " << selections << endl;
	cout << "Playing time in minutes: " << playtime << endl;
	
	Restore(f);
}
