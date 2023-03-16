#include <iostream>
#include <string>

using namespace std;

struct Pizza {
	string company;
	double diameter;
	double weight;
	void set();
	void show() const;
};

void Pizza::set() {
	cout << "Company name: ";
	getline(cin, company);
	cout << "Diameter: ";
	cin >> diameter;
	cout << "Weight: ";
	(cin >> weight).get();
}

void Pizza::show() const {
	cout << "Company name: " << company << '\n'
		 << "Diameter: " << diameter << '\n'
		 << "Weight: " << weight << endl;
}

int main(void) {
	Pizza pz;
	pz.set();
	cout << '\n';
	pz.show();
	
	return 0;
}
