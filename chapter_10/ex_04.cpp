#include <iostream>
#include "sales.h"

int main(void) {
	using std::cout;
	using std::endl;
	using SALES::Sales;
	Sales s1;
	
	s1.setSales();
	cout << endl;
	s1.showSales();
	
	double ad[6] = { 2100.0, 3700.0, 4400.0, 5100.0, 6400.0, 3600.0 };
	Sales s2(ad, 2);
	cout << endl;
	s2.showSales();
	
	Sales s3 = Sales(ad, Sales::QUARTERS);
	cout << endl;
	s3.showSales();
	
	Sales s4 = {ad, 6};
	cout << endl;
	s4.showSales();
	
	return 0;
}
