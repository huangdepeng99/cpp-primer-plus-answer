#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(void) {
	ifstream fin;
	string fname;
	cout << "Please enter a file name: ";
	getline(cin, fname);
	
	fin.open(fname);
	if (!fin.is_open()) {
		cerr << "Could not open the file " << fname << endl;
		exit(EXIT_FAILURE);
	}
	
	char c;
	int counter = 0;
	while (fin.get(c))
		++ counter;
	
	cout << counter << " characters" << endl;
	
	fin.close();
	
	return 0;
}
