#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string name, dessert;
	
    cout << "Enter your name:\n";
	getline(cin, name);
    cout << "Enter your favorite dessert:\n";
    getline(cin, dessert);
    cout << "I have some delicious " << dessert
		 << " for you, " << name << '.' << endl;
    
    return 0; 
}
