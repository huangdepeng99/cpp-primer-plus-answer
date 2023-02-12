#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

int reduce(long ar[], int n) {
	sort(ar, ar + n);
	auto it = unique(ar, ar + n);
	return it - ar;
}

int main(void) {
	long ar[] = { 20, 20, 60, 30, 30, 30, 50, 40, 10, 10 };
	int sz = sizeof(ar) / sizeof(ar[0]);
	ostream_iterator<long> out_it(cout, " ");
	
	cout << "Original array:" << endl;
	copy(ar, ar + sz, out_it);
	cout << endl;
	
	int nsz = reduce(ar, sz);
	cout << "After using the reduce() function:" << endl;
	copy(ar, ar + nsz, out_it);
	cout << endl;
	
	return 0;
}
