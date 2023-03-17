#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main(void) {
	const int MAX = 100;
	char word[MAX];
	const char * eoi = "done";	// end of input
	
	cout << "Enter words (to stop, type the word done):\n";
	int counter = 0;
	while (cin >> setw(MAX) >> word && strcmp(word, eoi))
		++ counter;
	
	cout << "You entered a total of " << counter << " words." << endl;
	
	return 0;
}
