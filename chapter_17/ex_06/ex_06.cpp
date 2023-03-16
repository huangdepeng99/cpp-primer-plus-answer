#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>
#include <unordered_map>
#include <utility>
#include <type_traits>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include "emp.h"

using namespace std;

enum class classkind /* : int */ {
	Employee, Manager, Fink, Highfink, Badkind
};
using ult_ck_t_ = underlying_type_t<classkind>;		// C++14

ostream & operator<<(ostream & os, classkind ck) {
	os << static_cast< ult_ck_t_ > (ck);
	return os;
}

const string opts = "abcd";
const unordered_map< char, pair< classkind, const char * > > opt2ck_map = {
	{ 'a', { classkind::Employee, "Employee" } },
	{ 'b', { classkind::Manager, "Manager" } },
	{ 'c', { classkind::Fink, "Fink" } },
	{ 'd', { classkind::Highfink, "Highfink" } }
};

const char * filename = "employee.dat";
const char * prompt = ">> ";

abstr_emp * make_employee(classkind ck);
void print_error(const string & msg);
void show_menu(void);
classkind option_to_classkind(char c);

int main(void) {
	ifstream fin(filename);
	if (fin.is_open()) {
		ult_ck_t_ classtype;
		char ch;
		cout << "Here are the current contents of the " << filename << " file:" << endl;
		while ((fin >> classtype).get(ch)) {
			unique_ptr<abstr_emp> p( make_employee( static_cast<classkind> (classtype) ) );
			if (!p) {
				ostringstream oss;
				oss << "The data in file " << filename << " is incorrect";
				print_error(oss.str());
			}
			p->ReadAll(fin);
			p->ShowAll();
			cout << endl;
		}
		fin.close();
	}
	
	ofstream fout(filename, ios_base::out | ios_base::app);
	if (!fout.is_open()) {
		ostringstream oss;
		oss << "Could not open file " << filename;
		print_error(oss.str());
	}
	cout << "Please select the type of data you want to add (press q to quit):" << endl;
	show_menu();
	cout << prompt;
	char choice;
	while (cin >> choice && choice != 'q') {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		classkind ck = option_to_classkind(choice);
		if (ck == classkind::Badkind) {
			cout << "Bad choice! Try again.\n";
		} else {
			unique_ptr<abstr_emp> p( make_employee(ck) );
			p->SetAll();
			fout << ck << '\n';
			p->WriteAll(fout);
		}
		cout << prompt;
	}
	fout.close();
	
	fin.open(filename);
	if (!fin.is_open()) {
		ostringstream oss;
		oss << "Could not open file " << filename;
		print_error(oss.str());
	}
	ult_ck_t_ classtype;
	char ch;
	cout << "\nHere are the new contents of the " << filename << " file:" << endl;
	while ((fin >> classtype).get(ch)) {
		unique_ptr<abstr_emp> p( make_employee( static_cast<classkind> (classtype) ) );
		p->ReadAll(fin);
		p->ShowAll();
		cout << endl;
	}
	fin.close();
	
	cout << "Done.\n";
	
	return 0;
}

abstr_emp * make_employee(classkind ck) {
	abstr_emp * p;
	switch (ck) {
		case classkind::Employee :
			p = new employee;	break;
		case classkind::Manager :
			p = new manager;	break;
		case classkind::Fink :
			p = new fink;		break;
		case classkind::Highfink :
			p = new highfink;	break;
		default :
			p = nullptr;		break;
	}
	return p;
}

void print_error(const string & msg) {
	cerr << msg << '\n';
	exit(EXIT_FAILURE);
}

void show_menu(void) {
	cout <<
	"-----------------------\n"
	"| option |    type    |\n"
	"-----------------------\n"
	;
	for (size_t i = 0; i < opts.size(); ++ i) {
	cout << left
	<< "| " << setw(6) << opts[i]
	<< " | " << setw(10) << opt2ck_map.find(opts[i])->second.second
	<< " |\n"
	<< "-----------------------\n"
	;
	}
	cout.flush();
}

classkind option_to_classkind(char c) {
	auto search_result = opt2ck_map.find(c);
	if (search_result == opt2ck_map.cend())
		return classkind::Badkind;
	return search_result->second.first;
}
