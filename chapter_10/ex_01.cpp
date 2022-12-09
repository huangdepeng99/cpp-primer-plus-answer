#include <iostream>
#include "BankAccount.h"

int main(void) {
	using std::cout;
	using std::endl;
	BankAccount ba1("Tom", "001");
	BankAccount ba2 = BankAccount("Jack", "002", 100.0);
	ba1.show();
	cout << endl;
	ba2.show();
	
	ba1.deposit(200.0);
	cout << endl;
	ba1.show();
	ba1.withdraw(20.0);
	cout << endl;
	ba1.show();
	
	cout << endl;
	ba2.withdraw(300.0);
	cout << endl;
	ba2.show();
	
	return 0;
}
