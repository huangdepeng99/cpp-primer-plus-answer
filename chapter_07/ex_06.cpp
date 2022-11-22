#include <iostream>

using namespace std;

int Fill_array(double *da, int size) {
	cout << "Please enter up to " << size << " numbers (enter non numbers to stop):" << endl;
	int i;
	for (i = 0; i < size; ++ i) {
		cout << "#" << i + 1 << ": ";
		cin >> da[i];
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				;
			break;
		}
	}
	
	return i;
}

void Show_array(const double *da, int size) {
	cout << "The contents of the array: " << endl;
	for (int i = 0; i < size; ++ i)
		cout << "#" << i + 1 << ": " << da[i] << endl;
}

void Reverse_array(double *da, int size) {
	for (int start = 0, end = size - 1; start < end; ++ start, -- end) {
		double temp = da[start];
		da[start] = da[end];
		da[end] = temp;
	}
}

int main(void) {
	const int size = 10;
	double da[size];
	int counter = Fill_array(da, size);
	if (counter == 0) {
		cout << "No data" << endl;
		return 0;
	}
	Show_array(da, counter);
	Reverse_array(da, counter);
	Show_array(da, counter);
	if (counter >= 4)
		Reverse_array(da + 1, counter - 2);
	Show_array(da, counter);
	
	return 0;
}
