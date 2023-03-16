#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

struct CandyBar {
	string brand;
	double weight;
	int calorie;
	void show() const;
};

void CandyBar::show() const {
	cout << "Brand: " << brand << '\n'
		 << "Weight: " << weight << '\n'
		 << "Calorie: " << calorie << endl;
}

int main(void) {
	const int ARR_SIZE = 3;
	CandyBar snacks[ARR_SIZE] = {
		{ "Mocha Munch", 2.3, 350 },
		{ "White Rabbit", 3.4, 500 },
		{ "Wang Zai", 2.7, 400 }
	};
	for_each(snacks, snacks + ARR_SIZE, mem_fn(&CandyBar::show));
	
	return 0;
}
