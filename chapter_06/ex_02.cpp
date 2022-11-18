#include <iostream>
#include <array>

using namespace std;

int main(void) {
	array<double, 10> donation = {};
	int idx = 0;
	while (idx < 10 && cin >> donation[idx])
		++ idx;
	
	double sum = 0.0;
	for (int i = 0; i < idx; ++ i)
		sum += donation[i];
	double average = sum / idx;

	int counter = 0;
	for (int i = 0; i < idx; ++ i)
		if (donation[i] > average)
			++ counter;

	cout << "average = " << average << endl;
	cout << counter << endl;
	
	return 0;
}
