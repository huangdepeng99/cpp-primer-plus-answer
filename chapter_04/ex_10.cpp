#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main(void) {
	const int ARR_SIZE = 3;
	array<double, ARR_SIZE> scores;
	
	cout << "Please enter the results of three 40-yard runs:\n";
	size_t sz = scores.size();
	for (size_t i = 0; i < sz; ++ i) {
		cout << i + 1 << ": ";
		cin >> scores[i];
	}
	
	double sum = 0.0;
	for_each(scores.cbegin(), scores.cend(), [&sum](double e) { sum += e; });
	cout << "Your average in " << sz << " 40-yard runs is " << sum / sz << endl;
	
	return 0;
}
