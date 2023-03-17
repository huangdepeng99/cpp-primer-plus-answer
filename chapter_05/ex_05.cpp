#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	const int MONTHS = 12;
	const char * months[MONTHS] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};
	int sales_volume[MONTHS];
	
	cout << "Please enter the sales volume for " << MONTHS << " months:\n";
	for (int i = 0; i < MONTHS; ++ i) {
		cout << months[i] << ": ";
		cin >> sales_volume[i];
	}
	int sum = 0;
	for_each(sales_volume, sales_volume + MONTHS, [&sum](int e) { sum += e; });
	cout << "The annual sales are " << sum << endl;
	
	return 0;
}
