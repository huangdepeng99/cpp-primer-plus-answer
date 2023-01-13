#include <iostream>
#include "BankAccount.h"

BankAccount::BankAccount(const std::string & client,
						const std::string & num, double bal)
{
	name = client;
	acctnum = num;
	balance = bal;
}

void BankAccount::show(void) const {
	using std::ios_base;
	using std::cout;
	using std::endl;
	ios_base::fmtflags ff = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize pre = cout.precision(2);
	
	cout << "name: " << name << endl
		 << "account number: " << acctnum << endl
		 << "balance: " << balance << endl;
	
	cout.flags(ff);
	cout.precision(pre);
}

void BankAccount::deposit(double cash) {
	if (cash < 0.0) {
		std::cerr << "The cash deposited can\'t be negative." << std::endl
				  << "Operation failed." << std::endl;
	} else
		balance += cash;
}

void BankAccount::withdraw(double cash) {
	if (cash < 0.0) {
		std::cerr << "The cash withdrawn can\'t be negative." << std::endl
				  << "Operation failed." << std::endl;
	} else if (cash > balance) {
		std::cerr << "You can\'t withdraw more than you have!" << std::endl
				  << "Operation failed." << std::endl;
	} else
		balance -= cash;
}
