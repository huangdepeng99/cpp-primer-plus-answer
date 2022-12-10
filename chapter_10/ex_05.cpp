#include <iostream>
#include "stack.h"

int main(void) {
	using std::cout;
	using std::endl;
	double total_money = 0.0;
	Stack s;
	Item item1 = { "Tom", 35.8 };
	if (s.isfull())
		cout << "stack already full" << endl;
	else
		s.push(item1);
	
	Item item2 = { "Jack", 120.0 };
	if (s.isfull())
		cout << "stack already full" << endl;
	else
		s.push(item2);
	
	Item item_temp;
	if (s.isempty())
		cout << "stack already empty" << endl;
	else {
		s.pop(item_temp);
		total_money += item_temp.payment;
		cout << "total money: " << total_money << endl;
	}
	
	if (s.isempty())
		cout << "stack already empty" << endl;
	else {
		s.pop(item_temp);
		total_money += item_temp.payment;
		cout << "total money: " << total_money << endl;
	}
	
	return 0;
}
