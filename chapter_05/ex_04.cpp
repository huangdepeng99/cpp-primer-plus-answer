#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
	const double principal_daphne = 100.0, principal_cleo = 100.0;	// 本金
	const double interest_rate_daphne = 0.1, interest_rate_cleo = 0.05;	// 利率
	const double interest_daphne = principal_daphne * interest_rate_daphne;	// Daphne 的利息
	double interest_cleo;	// Cleo 的利息
	double deposit_daphne = principal_daphne, deposit_cleo = principal_cleo;	// 存款
	int year = 0;
	auto show = [&year, &deposit_daphne, &deposit_cleo]() {
		cout << left
			 << setw(4) << year << setw(8) << deposit_daphne << setw(8) << deposit_cleo << endl;
	};
	
	cout << left
		 << setw(4) << ' ' << setw(8) << "Daphne" << setw(8) << "Cleo" << endl;
	show();
	while (deposit_cleo <= deposit_daphne) {
		interest_cleo = interest_rate_cleo * deposit_cleo;
		deposit_cleo += interest_cleo;
		deposit_daphne += interest_daphne;
		++ year;
		show();
	}
	
	return 0;
}
