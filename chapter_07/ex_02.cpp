#include <iostream>
#include <cassert>

using namespace std;

const int limit = 10;

int get_score(double *score, int size) {
	assert(size >= limit);
	cout << "Enter up to " << limit << " golf scores (enter non numbers to stop):" << endl;
	int i;
	for (i = 0; i < limit; ++ i) {
		cout << "#" << i + 1 << ": ";
		cin >> score[i];
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				;
			break;
		}
	}
	
	return i;
}

void show_score(const double *score, int size) {
	cout << "Scores: ";
	for (int i = 0; i < size; ++ i)
		cout << score[i] << " ";
	cout << endl;
}

double average_score(const double *score, int size) {
	double sum = 0.0;
	for (int i = 0; i < size; ++ i)
		sum += score[i];

	return sum / size;
}

int main(void) {
	double score[limit];
	int counter = get_score(score, limit);
	if (counter != 0) {
		show_score(score, counter);
		cout << "Average score: " << average_score(score, counter) << endl;
	} else {
		cout << "No data" << endl;
	}
	
	return 0;
}
