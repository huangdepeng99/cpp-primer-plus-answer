#include <iostream>

using namespace std;

template <typename T>
T max5(T arr[5]) {
	T m = arr[0];
	for (int i = 1; i < 5; ++ i)
		if (arr[i] > m)
			m = arr[i];
	return m;
}

int main(void) {
	int ai[5] = {1, 2, 3, 4, 5};
	double ad[5] = {1.1, 1.5, 2.4, 3.7, 8.3};
	
	cout << "The maximum value in array:" << endl;
	for (int i = 0; i < 5; ++ i)
		cout << ai[i] << " ";
	cout << endl;
	cout << "is " << max5(ai) << endl;
	cout << endl;
	
	cout << "The maximum value in array:" << endl;
	for (int i = 0; i < 5; ++ i)
		cout << ad[i] << " ";
	cout << endl;
	cout << "is " << max5<double>(ad) << endl;
	
	return 0;
}
