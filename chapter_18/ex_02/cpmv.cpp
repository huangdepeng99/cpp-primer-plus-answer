#include "cpmv.h"

#ifndef VERBOSE_
#include <iostream>
#endif

void Cpmv::display() const {
#ifdef VERBOSE_
	MESG_("void Cpmv::display() const called");
#endif
	if (pi) {
		std::cout << "first: " << pi->first << std::endl 
				  << "second: " << pi->second << std::endl;
	}
}
