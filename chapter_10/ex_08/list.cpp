#include <iostream>
#include "list.h"
namespace LIST {
	bool List::add(const Item & item) {
		if (!isfull()) {
			items[size++] = item;
			return true;
		} else
			return false;
	}
	
	void List::visit(void (*pf)(Item &)) {
		for (int i = 0; i < size; ++ i)
			pf(items[i]);
	}
	
	void show(Item & item) {
		std::cout << item << " ";
	}
}
