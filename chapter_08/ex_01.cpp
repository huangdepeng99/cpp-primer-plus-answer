#include <iostream>

using namespace std;

void print_string(const char *s, int n = 0) {
	static int cnt = 0;
	++ cnt;
	int limit = n ? cnt : 1;
	for (int i = 0; i < limit; ++ i)
		cout << s << endl;
}

int main(void) {
	const char *s = "Hello World!";
	cout << "call print_string(s):" << endl;
	print_string(s); cout << endl;
	cout << "call print_string(s, 0):" << endl;
	print_string(s, 0); cout << endl;
	cout << "call print_string(s, 1):" << endl;
	print_string(s, 1);
	
	return 0;
}
