#include <iostream>
#include <cstring>

using namespace std;

void showmenu(void) {
	cout << "Please enter one of the following choices:" << endl
		 << "c) carnivore p) pianist" << endl
		 << "t) tree g) game" << endl;
}

int main(void) {
	showmenu();
	const char *opts = "cptg";
	enum { c, p, t, g, };
	const char *msg[] = {
		[c] = "You describe yourself as a born-again carnivore.",
		[p] = "Howard is a talented pianist.",
		[t] = "A maple is a tree.",
		[g] = "The Match-Game is a simple and fun game.",
	};
	
	char choice;
	cin >> choice;
	while (!strchr(opts, choice)) {
		cout << "Please enter a c, p, t, or g: ";
		cin >> choice;
	}
	
	const char *output;
	switch (choice) {
		case 'c': output = msg[c]; break;
		case 'p': output = msg[p]; break;
		case 't': output = msg[t]; break;
		case 'g': output = msg[g]; break;
	}
	cout << output << endl;
	
	return 0;
}
