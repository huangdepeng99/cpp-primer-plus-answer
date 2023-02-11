#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

int main(void) {
	const char * filename = "wordlist";
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open()) {
		cerr << "Unable to open file " << filename << endl;
		exit(EXIT_FAILURE);
	}
	
	vector<string> wordlist;
	copy(istream_iterator<string>(fin), istream_iterator<string>(),
		 back_insert_iterator<vector<string> >(wordlist));
	
	fin.close();
	
    srand(time(nullptr));
    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);
    while (play == 'y') {
        string target = wordlist[rand() % wordlist.size()];
        size_t length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length
             << " letters, and you guess" << endl
             << "one letter at a time. You get " << guesses
             << " wrong guesses." << endl;
        cout << "Your word: " << attempt << endl;
        while (guesses > 0 && attempt != target) {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again." << endl;
                continue;
            }
            size_t loc = target.find(letter);
            if (loc == string::npos) {
                cout << "Oh, bad guess!" << endl;
                -- guesses;
                badchars += letter; // add to string
            }
            else {
                cout << "Good guess!" << endl;
                attempt[loc]=letter;
                // check if letter appears again
                loc = target.find(letter, loc + 1);
                while (loc != string::npos) {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
            if (attempt != target) {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left" << endl;
            }
        }
        if (guesses > 0)
            cout << "That's right!" << endl;
        else
            cout << "Sorry, the word is " << target << "." << endl;

        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }
    cout << "Bye" << endl;
	
    return 0; 
}
