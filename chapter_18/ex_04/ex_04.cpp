#include <iostream>
#include <algorithm>
#include <functional>
#include <list>

using namespace std;

using val_tp = int;
using fbi = function<bool(val_tp)>;

int main(void) {
	auto outval = [](val_tp n) { cout << n << ' '; };
	val_tp vals[] = { 50, 102, 90, 180, 60, 210, 415, 88, 188, 201 };
	size_t sz = sizeof(vals) / sizeof(vals[0]);
    list<val_tp> yadayada(vals, vals + sz);
    list<val_tp> etcetera(vals, vals + sz);
	
    cout << "Original lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outval);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outval);
    cout << endl;
	
    yadayada.remove_if( fbi( [](val_tp n) { return n > 100; } ) );
    etcetera.remove_if( fbi( [](val_tp n) { return n > 200; } ) );
    cout << "Trimmed lists:\n";
    for_each(yadayada.begin(), yadayada.end(), outval);
    cout << endl;
    for_each(etcetera.begin(), etcetera.end(), outval);
    cout << endl;
    
    return 0;
}
