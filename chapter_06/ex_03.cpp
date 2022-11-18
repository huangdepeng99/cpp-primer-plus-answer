#include <iostream>

using namespace std;

int main(void) {
	cout << "Please enter one of the following choices:" << endl
		 << "c) carnivore p) pianist" << endl
		 << "t) tree g) game" << endl;

	char c;
	cin >> c;
	while (c != 'c' && c != 'p' && c != 't' && c != 'g') {
		cout << "Please enter a c, p, t, or g: ";
		cin >> c;
	}
	
	switch (c) {
		case 'c': cout << "You describe yourself as a born-again carnivore." << endl;
				  break;
		case 'p': cout << "Howard is a talented pianist." << endl;
				  break;
		case 't': cout << "A maple is a tree." << endl;
				  break;
		case 'g': cout << "The Match-Game is a simple and fun game." << endl;
				  break;
	}
	
	return 0;
}
