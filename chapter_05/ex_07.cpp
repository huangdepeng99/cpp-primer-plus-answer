#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <functional>

using namespace std;

struct car {
	string make;
	int year;
	void set();
	void show() const;
};

void car::set() {
	cout << "Please enter the make: ";
	getline(cin, make);
	cout << "Please enter the year made: ";
	(cin >> year).get();
}

void car::show() const {
	cout << year << ' ' << make << endl;
}

int main(void) {
	int number;
	cout << "How many cars do you wish to catalog? ";
	(cin >> number).get();
	
	unique_ptr<car[]> pcars(new car[number]);
	
	for (int i = 0; i < number; ++ i) {
		cout << "Car #" << i + 1 << ":\n";
		pcars[i].set();
	}
	
	for_each(pcars.get(), pcars.get() + number, mem_fn(&car::show));
	
	return 0;
}
