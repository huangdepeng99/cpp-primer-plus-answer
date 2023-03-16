#include <iostream>

using namespace std;

int main(void) {
	long long n, sum = 0LL;
	cout << "Please enter an integer: ";
	while (cin >> n && n != 0LL) {
		sum += n;
		cout << "The current cumulative sum is "
			 << sum << endl;
		cout << "Please enter an integer: ";
	}
	
	return 0;
}
