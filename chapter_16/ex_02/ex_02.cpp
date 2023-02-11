#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(const string & s) {
	string rs(s);
	reverse(rs.begin(), rs.end());
	return rs == s;
}

int main(void) {
	string line;
	cout << "Please enter a string: ";
	getline(cin, line);
	cout << line << endl << "is " << (is_palindrome(line) ? "" : "not ")
		 << "a palindrome." << endl;
	
	return 0;
}
