#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void) {
	vector<int> vi0;
	size_t size = 10'000'000;	// since C++14
	
	srand(time(nullptr));
	for (size_t i = 0; i < size; ++ i)
		vi0.push_back(rand());
	
	vector<int> vi(vi0.begin(), vi0.end());
	list<int> li(vi0.begin(), vi0.end());
	
	clock_t start = clock();
	sort(vi.begin(), vi.end());
	clock_t end = clock();
	cout << (double) (end - start) / CLOCKS_PER_SEC << endl;
	
	start = clock();
	li.sort();
	end = clock();
	cout << (double) (end - start) / CLOCKS_PER_SEC << endl;
	
	copy(vi0.begin(), vi0.end(), li.begin());
	start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	end = clock();
	cout << (double) (end - start) / CLOCKS_PER_SEC << endl;
	
	return 0;
}
