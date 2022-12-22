#include <iostream>
#include "string2.h"

int main(void) {
	using std::cout;
	using std::endl;
	using std::cin;
	
	String s1(" and I an a C++ student.");
	String s2 = "Please enter your name: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << "." << endl;
	s2 = s2 + s1;
	s2.stringup();
	cout << "The string" << endl << s2 << endl << "contains " << s2.has('A')
		 << " \'A\' characters in it." << endl;
	s1 = "red";
	String rgb[3] = { String(s1), String("green"), String("blue") };
	cout << "Enter the name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while (cin >> ans) {
		ans.stringlow();
		for (int i = 0; i < 3; ++ i) {
			if (ans == rgb[i]) {
				cout << "That\'s right!" << endl;
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again!" << endl;
	}
	cout << "Bye" << endl;
	
	return 0;
}
