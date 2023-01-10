#include <iostream>
#include "workermi.h"
// Worker methods
Worker::~Worker() { }

void Worker::Get() {
	using std::cin;
	using std::cout;
	
	cout << "Enter " << Self() << "\'s name: ";
	std::getline(cin, fullname);
	cout << "Enter " << Self() << "\'s ID: ";
    cin >> id;
    while (cin.get() != '\n')
		continue;
}

void Worker::Data() const {
	std::cout << "Name: " << fullname << std::endl;
	std::cout << "Employee ID: " << id << std::endl;
}

const char * Worker::Self() const {
	return "worker";
}

// Waiter methods
void Waiter::Get() {
	using std::cin;
	
	std::cout << "Enter " << Self() << "\'s panache rating: ";
	cin >> panache;
    while (cin.get() != '\n')
		continue;
}

void Waiter::Data() const {
	std::cout << "Panache rating: " << panache << std::endl;
}

void Waiter::Set() {
    Worker::Get();
    Get();
}

void Waiter::Show() const {
	std::cout << "Category: " << Self() << std::endl;
    Worker::Data();
    Data();
}

// Singer methods
const char * Singer::pv[Singer::Vtypes] = {
	"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"
};

void Singer::Get() {
	using std::cin;
	using std::cout;
	using std::endl;
	
    cout << "Enter number for " << Self() << "\'s vocal range:" << endl;
	int i;
    for (i = 0; i < Vtypes; ++ i) {
        cout << i << ": " << pv[i];
        if (i % 4 == 3)
			cout << endl;
		else
			cout << ' ';
    }
    if (i % 4 != 0)
        cout << endl;
    while (cin >> voice && (voice < 0 || voice >= Vtypes))
        cout << "Please enter a value >= 0 and < " << Vtypes << endl;
    while (cin.get() != '\n')
		continue;
}

void Singer::Data() const {
	std::cout << "Vocal range: " << pv[voice] << std::endl;
}

void Singer::Set()
{
    Worker::Get();
    Get();
}

void Singer::Show() const {
	std::cout << "Category: " << Self() << std::endl;
    Worker::Data();
    Data();
}

// SingingWaiter methods
void SingingWaiter::Get() {
    Singer::Get();
    Waiter::Get();
}

void SingingWaiter::Data() const {
    Singer::Data();
    Waiter::Data();
}

void SingingWaiter::Set() {
    Worker::Get();
    Get();
}

void SingingWaiter::Show() const {
	std::cout << "Category: " << Self() << std::endl;
    Worker::Data();
    Data();
}
