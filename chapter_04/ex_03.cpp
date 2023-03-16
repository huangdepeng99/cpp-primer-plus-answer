#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	const int ARR_SIZE = 100;
	char first_name[ARR_SIZE];
	char last_name[ARR_SIZE];
	char name[ARR_SIZE] = { };
	
	cout << "Enter your first name: ";
	cin.getline(first_name, ARR_SIZE);
	cout << "Enter your last name: ";
	cin.getline(last_name, ARR_SIZE);
	strcat(name, last_name);
	strcat(name, ", ");
	strcat(name, first_name);
	cout << "Here\'s the information in a single string: "
		 << name << endl;
	
	return 0;
}
