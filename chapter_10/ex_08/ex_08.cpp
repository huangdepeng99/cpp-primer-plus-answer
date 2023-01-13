#include <iostream>
#include "list.h"

void multi(LIST::Item & item) {
	item *= 2;
}

int main(void) {
	using std::cout;
	using std::endl;
	LIST::Item item1 = 100;
	LIST::Item item2 = 30;
	LIST::List li;
	
	if (li.isempty())
		cout << "list is empty" << endl;
	
	if (li.isfull())
		cout << "list already full" << endl;
	else
		li.add(item1);
	
	if (li.isfull())
		cout << "list already full" << endl;
	else
		li.add(item2);
	
	li.visit(LIST::show);
	cout << endl;
	
	li.visit(multi);
	li.visit(LIST::show);
	cout << endl;
	
	return 0;
}
