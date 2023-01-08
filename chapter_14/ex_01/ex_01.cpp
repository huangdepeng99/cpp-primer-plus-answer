#include <iostream>
#include <string>
#include "winec.h"

int main(void) {
	using std::cin;
	using std::cout;
	using std::endl;
	
	cout << "Enter name of wine: ";
	std::string lab;
	std::getline(cin, lab);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;
	
	Wine holding(lab.c_str(), yrs);
	holding.GetBottles();
	holding.Show();
	
	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };
	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Label()
		 << ": " << more.sum() << endl;
	cout << "Bye" << endl;
	
	return 0;
}
