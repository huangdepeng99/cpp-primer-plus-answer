#include <cstring>
#include "classic.h"

Classic::Classic(const char * s1, const char * s2, const char * s3, int n, double x)
: Cd(s2, s3, n, x)
{
	std::strncpy(mainworks, s1, 99);
	mainworks[99] = '\0';
}

Classic::Classic(const char * s1, const Cd & d)
: Cd(d)
{
	std::strncpy(mainworks, s1, 99);
	mainworks[99] = '\0';
}

Classic::Classic()
// : Cd()
{
	mainworks[0] = '\0';
}

void Classic::Report() const {
	Cd::Report();
	std::cout << "Main works: " << mainworks << std::endl;
}
