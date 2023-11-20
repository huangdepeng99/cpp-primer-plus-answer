#include "cpmv.h"

#ifndef VERBOSE_
#include <iostream>
#endif

void Cpmv::display() const {
#ifdef VERBOSE_
	MESG_(__PRETTY_FUNCTION__);
#endif
	if (pi) {
		std::cout << "first: " << pi->first << std::endl 
				  << "second: " << pi->second << std::endl;
	}
}
