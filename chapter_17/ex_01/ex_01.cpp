#include <iostream>
#include <limits>

using namespace std;

int main(void) {
	// 解法1：
	size_t ct = 0;
	int c;
	while ((c = cin.peek()) != EOF && c != '$') {
		cin.get();
		++ ct;
	}
	cout << ct << endl;
	
//	解法2：
//	cin.ignore(numeric_limits<streamsize>::max(), '$');
//	streamsize ct = cin.gcount();
//	if (!cin.eof()) {
//		cin.unget();
//		-- ct;
//	}
//	cout << ct << endl;
	
	return 0;
}
