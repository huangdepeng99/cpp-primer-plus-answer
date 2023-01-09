#include <iostream>
#include <cstring>
#include "workermi.h"
#include "queuetp.h"

const int SIZE = 5;

int main(void) {
	using std::cin;
	using std::cout;
	using std::endl;
	
	QueueTP<Worker *> qw(SIZE);
	Worker * temp;
	
    int ct;
    for (ct = 0; ct < SIZE; ++ ct) {
        char choice;
        cout << "Enter the employee category:\n"
				"w: waiter  s: singer  "
				"t: singing waiter  q: quit"
			 << endl;
        cin >> choice;
        while (std::strchr("wstq", choice) == nullptr) {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice) {
            case 'w':	qw.enqueue(temp = new Waiter);
                        break;
            case 's':   qw.enqueue(temp = new Singer);
                        break;
            case 't':   qw.enqueue(temp = new SingingWaiter);
                        break;
        }
        cin.get();
        temp->Set();
    }
	
    cout << endl << "Here is your staff:" << endl;
    for (int i = 0; i < ct; ++ i) {
        cout << endl;
		qw.dequeue(temp);
        temp->Show();
		delete temp;
    }
    cout << "Bye." << endl;
	
    return 0;
}
