#include <iostream>
#include <string>

using namespace std;

struct donor {
	string name;
	double money;
};

int main(void) {
	int num;
	cout << "Please enter the number of donors: ";
	(cin >> num).get();
	
	donor *p = new donor[num];
	
	for (int i = 0; i < num; ++ i) {
		cout << "#" << i + 1 << endl;
		cout << "name: ";
		getline(cin, p[i].name);
		cout << "money: ";
		(cin >> p[i].money).get();
	}
	
	bool isEmpty = true;
	cout << endl;
	cout << "Grand Patrons" << endl;
	for (int i = 0; i < num; ++ i) {
		if (p[i].money > 10000) {
			isEmpty = false;
			cout << p[i].name << endl;
		}
	}
	if (isEmpty)
		cout << "none" << endl;
	
	isEmpty = true;
	cout << endl;
	cout << "Patrons" << endl;
	for (int i = 0; i < num; ++ i) {
		if (p[i].money <= 10000) {
			isEmpty = false;
			cout << p[i].name << endl;
		}
	}
	if (isEmpty)
		cout << "none" << endl;
	
	return 0;
}
