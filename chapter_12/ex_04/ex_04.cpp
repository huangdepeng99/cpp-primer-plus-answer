#include <iostream>
#include "stack.h"

int main(void) {
	Stack st1(5);
	Item item = 10;
	if (!st1.isfull())
		st1.push(item);
	if (!st1.isempty())
		st1.pop(item);
	
	if (!st1.isfull())
		st1.push(item);
	Stack st2 = st1;
	
	Stack st3;
	st3 = st2;
	
    return 0;
}
