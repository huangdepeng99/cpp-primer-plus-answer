#include <iostream>
#include <string>

using namespace std;

const int Seasons = 4;

const char *Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

struct arr {
	double d[Seasons];
};

void fill(arr *pa) {
    for (int i = 0; i < Seasons; ++ i) {
		cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (pa->d)[i];
    }
}

void show(arr a) {
    double total = 0.0;
    cout << endl << "EXPENSES" << endl;
    for (int i = 0; i < Seasons; ++ i) {
        cout << Snames[i] << ": $" << (a.d)[i] << endl;
        total += (a.d)[i];
    }
    cout << "Total: $" << total << endl;
}

int main(void) {
	arr expenses;
    fill(&expenses);
    show(expenses);
	
    return 0;
}
