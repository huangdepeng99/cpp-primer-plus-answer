#include <iostream>

using namespace std;

long double probability(unsigned numbers, unsigned picks) {
    long double result = 1.0;
    long double n;
    unsigned p;
	
    for (n = numbers, p = picks; p > 0; -- n, -- p)
        result = result * n / p ; 
    return result;
}

int main(void) {
    unsigned total = 47, choices = 5;
	cout << "You have one chance in "
		 << probability(total, choices) * 27.0L
		 << " of winning." << endl;
	
    return 0;
}
