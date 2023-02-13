#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> lotto(int n, int p) {
	vector<int> numbers;
	for (int i = 1; i <= n; ++ i)
		numbers.push_back(i);
	
	srand(time(nullptr));
	vector<int> picks;
	for (int i = 0; i < p; ++ i) {
		random_shuffle(numbers.begin(), numbers.end(),
					   [](int i){ return rand() % i; });
		picks.push_back(numbers.back());
		numbers.pop_back();
	}
	sort(picks.begin(), picks.end());
	
	return picks;
}

int main(void) {
	vector<int> winners;
	winners = lotto(51, 6);
	cout << "The winner is:" << endl;
	copy(winners.begin(), winners.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	return 0;
}
