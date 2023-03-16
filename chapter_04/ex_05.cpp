#include <iostream>
#include <string>

using namespace std;

struct CandyBar {
	string brand;
	double weight;
	int calorie;
};

int main(void) {
	CandyBar snack = { "Mocha Munch", 2.3, 350 };
	cout << "Brand: " << snack.brand << '\n'
		 << "Weight: " << snack.weight << '\n'
		 << "Calorie: " << snack.calorie << endl;
	
	return 0;
}
