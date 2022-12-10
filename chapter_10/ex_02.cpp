#include <iostream>
#include "Person.h"

int main(void) {
	using std::cout;
	using std::endl;
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	
	one.Show();
	cout << endl;
	one.FormalShow();
	
	cout << endl;
	two.Show();
	cout << endl;
	two.FormalShow();
	
	cout << endl;
	three.Show();
	cout << endl;
	three.FormalShow();
	
	return 0;
}
