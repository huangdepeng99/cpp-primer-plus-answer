#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string name;
	string address;
	
	cout << "Please enter your name: ";
	getline(cin, name);
	cout << "Please enter your address: ";
	getline(cin, address);
	
	cout << "Your name: " << name << '\n'
		 << "Your address: " << address << endl;
	
	return 0;
}
