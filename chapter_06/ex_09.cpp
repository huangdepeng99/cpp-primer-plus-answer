#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct donor {
	string name;
	double money;
};

int main(void) {
	string fname;
	cout << "Please enter a file name: ";
	getline(cin, fname);
	
	ifstream fin;
	fin.open(fname);
	if (!fin.is_open()) {
		cerr << "Could not open the file " << fname << endl;
		exit(EXIT_FAILURE);
	}
	
	int num;
	(fin >> num).get();
	
	donor *p = new donor[num];
	
	for (int i = 0; i < num; ++ i) {
		cout << "#" << i + 1 << endl;
		getline(fin, p[i].name);
		cout << "name: " << p[i].name << endl;
		(fin >> p[i].money).get();
		cout << "money: " << p[i].money << endl;
	}

	fin.close();
	
	bool isEmpty = true;
	cout << endl;
	cout << "Grand Patrons" << endl;
	for (int i = 0; i < num; ++ i) {
		if (p[i].money > 10000) {
			isEmpty = false;
			cout << p[i].name << endl;
		}
	}
	if (isEmpty)
		cout << "none" << endl;
	
	isEmpty = true;
	cout << endl;
	cout << "Patrons" << endl;
	for (int i = 0; i < num; ++ i) {
		if (p[i].money <= 10000) {
			isEmpty = false;
			cout << p[i].name << endl;
		}
	}
	if (isEmpty)
		cout << "none" << endl;
	
	return 0;
}
