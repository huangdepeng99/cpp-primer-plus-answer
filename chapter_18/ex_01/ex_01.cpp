#include <iostream>
#include <algorithm>
#include <type_traits>
#include <initializer_list>

using namespace std;

template< typename T >
T average_list(initializer_list<T> il) {
	static_assert(is_arithmetic<T>::value,
				  "error on instantiation, average_list requires arithmetic");
	long double total_ = 0.0L;
	for_each(il.begin(), il.end(),
			 [&total_](T x_) { total_ += x_; });
	return static_cast<T> (total_ / il.size());
}

// 下面是更通用的版本：
// template< typename T >
// T average_list(initializer_list<T> il) {
//     T total_ { };
//     for_each(il.begin(), il.end(),
//              [&total_](const T & x_) { total_ = total_ + x_; });
//     return total_ / static_cast<long double> (il.size());
// }

int main(void) {
	auto q = average_list( { 15.4, 10.7, 9.0 } );
	cout << q << endl;
	
	cout << average_list( { 20, 30, 19, 17, 45, 38 } ) << endl;
	
	auto ad = average_list<double>( { 'A', 70, 65.33 } );
	cout << ad << endl;
	
	return 0;
}
