#include <iostream>

using namespace std;

const int strsize = 50;
const int num = 5;

struct bop {
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};

void showmenu(void) {
	cout << "Benevolent Order of Programmer Report" << endl
		 << "a. display by name      b. display by title" << endl
		 << "c. display by bopname   d. display by preference" << endl
		 << "q. quit" << endl;	
}

int main(void) {
	bop arr[num] = {
		{"Wimp Macho", "AAA", "WM", 0},
		{"Raki Rhodes", "Junior Programmer", "RR", 1},
		{"Celia Laiter", "BBB", "MIPS", 2},
		{"Hoppy Hipman", "Analyst Trainee", "HH", 1},
		{"Pat Hand", "CCC", "LOOPY", 2},
	};
	
	showmenu();

	char choice;
	cout << "Enter your choice: ";
	cin >> choice;
	while (choice != 'q') {
		if (choice == 'a') {
			for (int i = 0; i < num; ++ i)
				cout << arr[i].fullname << endl;
		} else if (choice == 'b') {
			for (int i = 0; i < num; ++ i)
				cout << arr[i].title << endl;
		} else if (choice == 'c') {
			for (int i = 0; i < num; ++ i)
				cout << arr[i].bopname << endl;
		} else if (choice == 'd') {
			for (int i = 0; i < num; ++ i) {
				switch (arr[i].preference) {
					case 0: cout << arr[i].fullname << endl; break;
					case 1: cout << arr[i].title << endl; break;
					case 2: cout << arr[i].bopname << endl; break;
				}
			}
		} else {
			cerr << "That\'s not a choice!" << endl;
		}
		cout << "Next choice: ";
		cin >> choice;
	}
	cout << "Bye!" << endl;
	
	return 0;
}
