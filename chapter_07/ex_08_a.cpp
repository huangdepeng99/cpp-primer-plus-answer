#include <iostream>
#include <string>

using namespace std;

const int Seasons = 4;

const char *Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

void fill(double *pd, int size) {
    for (int i = 0; i < size; ++ i) {
		cout << "Enter " << Snames[i] << " expenses: ";
        cin >> pd[i];
    }
}

void show(const double *pd, int size) {
    double total = 0.0;
    cout << endl << "EXPENSES" << endl;
    for (int i = 0; i < size; ++ i) {
        cout << Snames[i] << ": $" << pd[i] << endl;
        total += pd[i];
    }
    cout << "Total: $" << total << endl;
}

int main(void) {
    double expenses[Seasons];
    fill(expenses, Seasons);
    show(expenses, Seasons);
	
    return 0;
}
