#include <iostream>
#include <string>

void strcount(const std::string & str) {
	using std::cout;
	using std::endl;
    static std::size_t total = 0;
	std::size_t count = str.size();
    total += count;
	
    cout << "\"" << str <<"\" contains ";
    cout << count << " characters" << endl;
    cout << total << " characters total" << endl;
}

int main(void) {
	using std::cin;
	using std::cout;
	using std::endl;
	std::string input;
	
    cout << "Enter a line (empty line to quit):" << endl;
	std::getline(cin, input);
    while (cin.good() && input != "") {
        strcount(input);
        cout << "Enter next line (empty line to quit):" << endl;
		std::getline(cin, input);
    }
    cout << "Bye" << endl;
	
    return 0;
}
