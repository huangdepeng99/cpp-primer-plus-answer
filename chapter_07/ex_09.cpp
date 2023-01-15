#include <iostream>
#include <string>
#include <cstdlib>
#include <new>

using namespace std;

struct student {
	string fullname;
	string hobby;
	int ooplevel;
};

int getinfo(student pa[], int n) {
	cout << "Enter up to " << n << " students\' information (leave students\' name blank to stop):" << endl;
	int i;
	for (i = 0; i < n; ++ i) {
		cout << "#" << i + 1 << ":" << endl;
		cout << "fullname: ";
		getline(cin, pa[i].fullname);
		if (pa[i].fullname.size() == 0)
			break;
		cout << "hobby: ";
		getline(cin, pa[i].hobby);
		cout << "ooplevel: ";
		while (!(cin >> pa[i].ooplevel)) {
			cin.clear();
			while (cin.get() != '\n')
				;
			cout << "Bad input! Please enter an integer: ";
		}
		while (cin.get() != '\n')
			;
	}
	
	return i;
}

void display1(student st) {
	cout << "fullname: " << st.fullname << endl;
	cout << "hobby: " << st.hobby << endl;
	cout << "ooplevel: " << st.ooplevel << endl;
}

void display2(const student *ps) {
	cout << "fullname: " << ps->fullname << endl;
	cout << "hobby: " << ps->hobby << endl;
	cout << "ooplevel: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n) {
	for (int i = 0; i < n; ++ i) {
		cout << "#" << i + 1 << ": " << endl;
		cout << "fullname: " << pa[i].fullname << endl;
		cout << "hobby: " << pa[i].hobby << endl;
		cout << "ooplevel: " << pa[i].ooplevel << endl;
	}
}

int main(void) {
	const int maxClassSize = 1000;
	cout << "Enter class size (integer greater than 0 and less than or equal to "
		 << maxClassSize << "): ";
	int class_size;
	while (true) {
		while (!(cin >> class_size)) {
			cin.clear();
			while (cin.get() != '\n')
				;
			cout << "Bad input! Please enter an integer: ";
		}
		while (cin.get() != '\n')
			;
		if (0 < class_size && class_size <= maxClassSize)
			break;
		cout << "Bad input! The number is out of range!" << endl;
		cout << "Please enter an integer greater than 0 and less than or equal to " << maxClassSize <<": ";
	}
	
	student *ptr_stu = new (nothrow) student[class_size];
	if (ptr_stu == nullptr) {
		cerr << "Out of space!" << endl;
		exit(EXIT_FAILURE);
	}
	int entered = getinfo(ptr_stu, class_size);
	if (entered == 0) {
		cerr << "No data!" << endl;
		delete [] ptr_stu;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < entered; ++ i) {
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done" << endl;
	
	return 0;
}
