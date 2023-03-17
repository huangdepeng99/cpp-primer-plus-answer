#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	const int YEARS = 3;
	const int MONTHS = 12;
	const char * years[YEARS] = {
		"first", "second", "third"
	};
	const char * months[MONTHS] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};
	int sales_volume[YEARS][MONTHS];
	int annual_sales[YEARS] = { };
	int total_sales = 0;
	
	cout << "Please enter the sales volume for " << YEARS << " years:\n";
	for (int i = 0; i < YEARS; ++ i) {
		cout << ">> The " << years[i] << " year <<\n";
		for (int j = 0; j < MONTHS; ++ j) {
			cout << months[j] << ": ";
			cin >> sales_volume[i][j];
			annual_sales[i] += sales_volume[i][j];
		}
		cout << "The " << years[i] << " year sales were " << annual_sales[i] << endl;
	}
	for_each(annual_sales, annual_sales + YEARS, [&total_sales](int e) { total_sales += e; });
	cout << "\nThe total sales in " << YEARS << " years is " << total_sales << endl;
	
	return 0;
}
