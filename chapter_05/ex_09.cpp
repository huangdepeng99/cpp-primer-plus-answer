#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string word;
	const char * eoi = "done";	// end of input
	
	cout << "Enter words (to stop, type the word done):\n";
	int counter = 0;
	while (cin >> word && word != eoi)
		++ counter;
	
	cout << "You entered a total of " << counter << " words." << endl;
	
	return 0;
}
