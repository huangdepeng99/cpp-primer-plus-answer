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
	string word;
	cout << "Please enter a word: ";
	cin >> word;
	cout << word << endl << "is " << (is_palindrome(word) ? "" : "not ")
		 << "a palindrome." << endl;
	
	return 0;
}
