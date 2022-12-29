#include <cstring>
#include "cd.h"

// auto Cd::SetFormat() -> Formatting {
Cd::Formatting Cd::SetFormat() {
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
	std::strncpy(performers, s1, 49);
	performers[49] = '\0';
	std::strncpy(label, s2, 19);
	label[19] = '\0';
	selections = n;
	playtime = x;
}

Cd::Cd() {
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
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
