#include <iostream>

using namespace std;

inline void show(int h, int m) {
	cout << "Time: " << h << ':' << m << endl;
}

int main(void) {
	int h, m;
	cout << "Enter the number of hours: ";
	cin >> h;
	cout << "Enter the number of minutes: ";
	cin >> m;
	show(h, m);
	
	return 0;
}
