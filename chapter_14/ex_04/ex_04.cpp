#include <iostream>
#include <cstring>
#include "personmi.h"

const int SIZE = 5;

int main(void) {
	using std::cin;
	using std::cout;
	using std::endl;
	
	Person * lolas[SIZE];
	
    int ct;
    for (ct = 0; ct < SIZE; ++ ct) {
        char choice;
        cout << "Enter the person category:\n"
				"g: gunslinger  p: pockerplayer  "
				"b: baddude  q: quit"
			 << endl;
        cin >> choice;
        while (std::strchr("gpbq", choice) == nullptr) {
            cout << "Please enter a g, p, b, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice) {
            case 'g':   lolas[ct] = new Gunslinger;
                        break;
            case 'p':   lolas[ct] = new PockerPlayer;
                        break;
            case 'b':   lolas[ct] = new BadDude;
                        break;
        }
        cin.get();
        lolas[ct]->Set();
    }
	
    cout << endl << "Here is your staff:" << endl;
    int i;
    for (i = 0; i < ct; ++ i) {
        cout << endl;
        lolas[i]->Show();
    }
    for (i = 0; i < ct; ++ i)
        delete lolas[i];
    cout << "Bye." << endl;
	
    return 0;
}
