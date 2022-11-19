#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

int main(void) {
	string word;
	int vowels = 0, consonants = 0, others = 0;

	cout << "Enter words (q to quit):" << endl;
	cin >> word;
	while (word != "q") {
		if (isalpha(word[0])) {
			if (strchr("aeiouAEIOU", word[0]))
				++ vowels;
			else
				++ consonants;
		} else {
			++ others;
		}
		cin  >> word;
	}
	
	cout << vowels << " words beginning with vowels" << endl;
	cout << consonants << " words beginning with consonants" << endl;
	cout << others << " others" << endl;
	
	return 0;
}
