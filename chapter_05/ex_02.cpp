#include <iostream>
#include <array>

using namespace std;

const int ARR_SIZE = 101;

int main(void) {
	array<long double, ARR_SIZE> factorials;
    factorials[0] = factorials[1] = 1.0L;
    for (int i = 2; i < ARR_SIZE; ++ i)
        factorials[i] = i * factorials[i-1];
    for (int i = 0; i < ARR_SIZE; ++ i)
        cout << i << "! = " << factorials[i] << endl;
	
    return 0;
}
