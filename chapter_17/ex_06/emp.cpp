#include "emp.h"

// abstr_emp methods
const char * abstr_emp::Self() const {
	return "abstr_emp";
}

abstr_emp::~abstr_emp()
{ }

void abstr_emp::SetAll() {
	using std::cin;
	using std::cout;
	using std::getline;
	
	cout << "Enter " << Self() << "\'s first name: ";
	getline(cin, fname);
	cout << "Enter " << Self() << "\'s last name: ";
	getline(cin, lname);
	cout << "Enter " << Self() << "\'s job: ";
	getline(cin, job);
}

void abstr_emp::ShowAll() const {
	using std::cout;
	using std::endl;
	
	cout << "Category: " << Self() << endl;
	cout << "Name: " << fname << ' ' << lname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::ReadAll(std::istream & is) {
	using std::getline;
	getline(is, fname);
	getline(is, lname);
	getline(is, job);
}

void abstr_emp::WriteAll(std::ostream & os) const {
	os << fname << '\n'
	   << lname << '\n'
	   << job << std::endl;
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e) {
	std::cout << "Category: " << e.Self() << std::endl
			  << e.fname << ' ' << e.lname << ", "
			  << e.job;
	return os;
}

// manager methods
void manager::SetAll() {
	abstr_emp::SetAll();
	std::cout << "Enter " << Self() << "\'s inchargeof: ";
	std::cin >> inchargeof;
	while (std::cin.get() != '\n')
		continue;
}

void manager::ShowAll() const {
	abstr_emp::ShowAll();
	std::cout << "Inchargeof: " << inchargeof << std::endl;
}

void manager::ReadAll(std::istream & is) {
	abstr_emp::ReadAll(is);
	(is >> inchargeof).get();
}

void manager::WriteAll(std::ostream & os) const {
	abstr_emp::WriteAll(os);
	os << inchargeof << std::endl;
}

std::ostream & operator<<(std::ostream & os, const manager & m) {
	std::cout << (const abstr_emp &) m << ", " << m.inchargeof;
	return os;
}

// fink methods
void fink::SetAll() {
	abstr_emp::SetAll();
	std::cout << "Enter " << Self() << "\'s reportsto: ";
	std::getline(std::cin, reportsto);
}

void fink::ShowAll() const {
	abstr_emp::ShowAll();
	std::cout << "Reportsto: " << reportsto << std::endl;
}

void fink::ReadAll(std::istream & is) {
	abstr_emp::ReadAll(is);
	std::getline(is, reportsto);
}

void fink::WriteAll(std::ostream & os) const {
	abstr_emp::WriteAll(os);
	os << reportsto << std::endl;
}

std::ostream & operator<<(std::ostream & os, const fink & f) {
	std::cout << (const abstr_emp &) f << ", " << f.reportsto;
	return os;
}

// highfink methods
void highfink::SetAll() {
	manager::SetAll();
	std::cout << "Enter " << Self() << "\'s reportsto: ";
	std::getline(std::cin, ReportsTo());
}

void highfink::ShowAll() const {
	manager::ShowAll();
	std::cout << "Reportsto: " << ReportsTo() << std::endl;
}

void highfink::ReadAll(std::istream & is) {
	manager::ReadAll(is);
	std::getline(is, ReportsTo());
}

void highfink::WriteAll(std::ostream & os) const {
	manager::WriteAll(os);
	os << ReportsTo() << std::endl;
}

std::ostream & operator<<(std::ostream & os, const highfink & hf) {
	std::cout << (const manager &) hf << ", " << hf.ReportsTo();
	return os;
}
