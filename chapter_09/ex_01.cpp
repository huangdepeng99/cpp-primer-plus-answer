#include <iostream>
#include <cstdlib>
#include "golf.h"

int main(void) {
	using std::cout;
	using std::endl;
	const int ng = 5;
	golf ag[ng];
	
	int idx;
	for (idx = 0; idx < ng; ++ idx) {
		cout << "#" << idx + 1 << endl;
		int rv = setgolf(ag[idx]);
		if (rv == 0)
			break;
	}
	
	cout << endl;
	if (idx == 0) {
		std::cerr << "No data!" << endl;
		std::exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < idx; ++ i) {
		cout << "#" << i + 1 << endl;
		showgolf(ag[i]);
	}
	
	cout << endl;
	handicap(ag[idx-1], 10);
	showgolf(ag[idx-1]);
	
	cout << endl;
	golf gf;
	setgolf(gf, "Ann Birdfree", 24);
	showgolf(gf);
	
	return 0;
}
