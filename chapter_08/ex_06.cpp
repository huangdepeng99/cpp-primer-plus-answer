#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T maxn(T arr[], int n) {
	T m = arr[0];
	for (int i = 1; i < n; ++ i)
		if (arr[i] > m)
			m = arr[i];
	return m;
}

template <> char *maxn<char *>(char *arr[], int n) {
	char *m = arr[0];
	for (int i = 1; i < n; ++ i)
		if (strlen(arr[i]) > strlen(m))
			m = arr[i];
	return m;
}

template <> const char *maxn<const char *>(const char *arr[], int n) {
	const char *m = arr[0];
	for (int i = 1; i < n; ++ i)
		if (strlen(arr[i]) > strlen(m))
			m = arr[i];
	return m;
}

int main(void) {
	int ai[6] = {1, 2, 3, 4, 5, 6};
	double ad[4] = {2.2, 3.7, 4.3, 9.2};
	const char *acs[5] = {
		"Hello World!",
		"Hi! Siri.",
		"My name is Jack.",
		"My name is Tony.",
		"Apple",
	};
	char s1[] = "Hello World!";
	char s2[] = "Hi! Siri.";
	char s3[] = "My name is Jack.";
	char s4[] = "My name is Tony.";
	char s5[] = "Apple";
	char *as[5] = {s1, s2, s3, s4, s5};
	
	cout << "The maximum value in array:" << endl;
	for (int i = 0; i < 6; ++ i)
		cout << ai[i] << " ";
	cout << endl;
	cout << "is " << maxn(ai, 6) << endl;
	cout << endl;
	
	cout << "The maximum value in array:" << endl;
	for (int i = 0; i < 4; ++ i)
		cout << ad[i] << " ";
	cout << endl;
	cout << "is " << maxn<double>(ad, 4) << endl;
	cout << endl;
	
	cout << "The longest string in array:" << endl;
	for (int i = 0; i < 5; ++ i)
		cout << "\"" << acs[i] << "\"" << endl;
	cout << "is \"" << maxn(acs, 5) << "\"" << endl;
	cout << endl;
	
	cout << "The longest string in array:" << endl;
	for (int i = 0; i < 5; ++ i)
		cout << "\"" << as[i] << "\"" << endl;
	cout << "is \"" << maxn(as, 5) << "\"" << endl;
	
	return 0;
}
