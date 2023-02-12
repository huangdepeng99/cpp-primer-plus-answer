#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

template<typename T>
int reduce(T ar[], int n) {
	sort(ar, ar + n);
	auto it = unique(ar, ar + n);
	return it - ar;
}

int main(void) {
	long al[] = { 20, 20, 60, 30, 30, 30, 50, 40, 10, 10 };
	int szl = sizeof(al) / sizeof(al[0]);
	ostream_iterator<long> out_it_l(cout, " ");
	
	cout << "Original long array:" << endl;
	copy(al, al + szl, out_it_l);
	cout << endl;
	
	int nszl = reduce<long>(al, szl);
	cout << "After using the reduce() function:" << endl;
	copy(al, al + nszl, out_it_l);
	cout << endl;
	
	cout << endl;
	string as[] = {
		"blue", "apple", "apple", "tree", "banana",
		"banana", "banana", "yellow", "red", "red"
	};
	int szs = sizeof(as) / sizeof(as[0]);
	ostream_iterator<string> out_it_s(cout, " ");
	
	cout << "Original string array:" << endl;
	copy(as, as + szs, out_it_s);
	cout << endl;
	
	int nszs = reduce(as, szs);
	cout << "After using the reduce() function:" << endl;
	copy(as, as + nszs, out_it_s);
	cout << endl;
	
	return 0;
}
