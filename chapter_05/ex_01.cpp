#include <iostream>

using namespace std;

int main(void) {
	int begin, end;
	cout << "Please enter the value range: ";
	cin >> begin >> end;
	int sum = 0;
	for (int i = begin; i <= end; ++ i)
		sum += i;
	cout << "The sum of all integers in the range "
		 << '[' << begin << ',' << end << "] is "
		 << sum << endl;
	
	return 0;
}
