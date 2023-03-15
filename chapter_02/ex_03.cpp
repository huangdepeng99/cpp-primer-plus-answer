#include <iostream>

using namespace std;

inline void show1(void) {
	cout << "Three blind mice" << endl;
}

inline void show2(void) {
	cout << "See how they run" << endl;
}

int main(void) {
	show1();
	show1();
	show2();
	show2();
	
	return 0;
}
