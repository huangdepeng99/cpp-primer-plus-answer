#include <iostream>
#include "sales.h"

int main(void) {
	using std::cout;
	using std::endl;
	using SALES::setSales;
	using SALES::showSales;
	SALES::Sales s1, s2;
	
	setSales(s1);
	cout << endl;
	showSales(s1);
	
	double ad[6] = {2100, 3700, 4400, 5100, 6400, 3600};
	setSales(s2, ad, 2);
	cout << endl;
	showSales(s2);
	
	setSales(s2, ad, SALES::QUARTERS);
	cout << endl;
	showSales(s2);
	
	setSales(s2, ad, 6);
	cout << endl;
	showSales(s2);
	
	return 0;
}
