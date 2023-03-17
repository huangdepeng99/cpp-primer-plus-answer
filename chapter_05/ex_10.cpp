#include <iostream>

using namespace std;

void repeat(char c, int t) {
	for (int i = 0; i < t; ++ i)
		cout << c;
}

int main(void) {
	int rows, columns;
	cout << "How many rows do you want to display? ";
	cin >> rows;
	columns = rows;
	
	for (int i = 0; i < rows; ++ i) {
		int asterisks = i + 1;
		int periods = columns - asterisks;
		repeat('.', periods);
		repeat('*', asterisks);
		cout << endl;
	}
	
	return 0;
}
