#include <iostream>
#include "Move.h"

int main(void) {
	Move m1;
	m1.showmove();
	m1.reset(1, 1);
	m1.showmove();
	
	Move m2(2, 2);
	m2.showmove();
	
	Move m3 = m1.add(m2);
	m3.showmove();
	
	m2.add(m3).showmove();
	
	return 0;
}
