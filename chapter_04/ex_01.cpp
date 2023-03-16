#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string first_name, last_name;
	char letter_grade;
	int age;
	
	cout << "What is your first name? ";
	getline(cin, first_name);
	cout << "What is your last name? ";
	getline(cin, last_name);
	cout << "What letter grade do you deserve? ";
	(cin >> letter_grade).get();
	cout << "What is your age? ";
	(cin >> age).get();
	
	cout << "Name: " << last_name << ", " << first_name << '\n'
		 << "Grade: " << char(letter_grade + 1) << '\n'
		 << "Age: " << age << endl;
	
	return 0;
}
