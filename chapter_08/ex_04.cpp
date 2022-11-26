#include <iostream>
#include <cstring>

using namespace std;

struct stringy {
	char *str;
	int ct;
};

void set(stringy &sy, const char *s) {
	size_t size = strlen(s);
	sy.ct = size;
	sy.str = new char[size + 1];
	strcpy(sy.str, s);
}

void show(const stringy &s, int n = 1) {
	for (int i = 0; i < n; ++ i)
		cout << s.str << endl;
}

void show(const char *s, int n = 1) {
	for (int i = 0; i < n; ++ i)
		cout << s << endl;
}

int main(void) {
	stringy beany;
	char testing[] = "Reality isn\'t what it used to be.";
	
	set(beany, testing);
	show(beany);
	cout << endl;
	show(beany, 2);
	cout << endl;
	
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	cout << endl;
	show(testing, 3);
	cout << endl;
	show("Done!");
	
	return 0;
}
