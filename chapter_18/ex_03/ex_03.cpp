#include <iostream>

using namespace std;

// 下面这种方案行不通：
// template< typename T, typename... Args >
// long double sum_value(const T & val, const Args &... args) {
//     return sizeof...(args) ? val + sum_value(args...) : val;
// }

template< typename T >
long double sum_value(const T & val) {
	return val;
}

template< typename T, typename... Args >
long double sum_value(const T & val, const Args &... args) {
	return val + sum_value(args...);
}

int main(void) {
	cout << sum_value(3.14) << endl;
	cout << sum_value(3.14, 17, 'A') << endl;
	
	return 0;
}
