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
		int rv = ag[idx].setgolf();
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
		ag[i].showgolf();
	}
	
	cout << endl;
	ag[idx-1].sethandicap(10);
	ag[idx-1].showgolf();
	
	cout << endl;
	golf gf("Ann Birdfree", 24);
	gf.showgolf();
	
	return 0;
}
