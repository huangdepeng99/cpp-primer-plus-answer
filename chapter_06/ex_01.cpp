#include <iostream>
#include <cctype>

using namespace std;

int main(void) {
	char c;

	cin.get(c);
	while (c != '@') {
		if (isdigit(c))
			;
		else if (isupper(c))
			cout << (char) tolower(c);
		else if (islower(c))
			cout << (char) toupper(c);
		else
			cout << c;
		
		cin.get(c);
	}
	
	return 0;
}

