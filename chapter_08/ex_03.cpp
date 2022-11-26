#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void string_to_upper(string &s) {
	for (auto &c: s)
		c = toupper(c);
}

int main(void) {
	string s;
	cout << "Enter a string (q to quit): ";
	getline(cin, s);
	while (s != "q") {
		string_to_upper(s);
		cout << s << endl;
		cout << "Next string (q to quit): ";
		getline(cin, s);
	}
	cout << "Bye." << endl;
	
	return 0;
}
