#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Pizza {
	double diameter;
	string company;
	double weight;
	void set();
	void show() const;
};

void Pizza::set() {
	cout << "Diameter: ";
	(cin >> diameter).get();
	cout << "Company name: ";
	getline(cin, company);
	cout << "Weight: ";
	(cin >> weight).get();
}

void Pizza::show() const {
	cout << "Diameter: " << diameter << '\n'
		 << "Company name: " << company << '\n'
		 << "Weight: " << weight << endl;
}

int main(void) {
	unique_ptr<Pizza> pz(new Pizza);
	pz->set();
	cout << '\n';
	pz->show();
	
	return 0;
}
