#include <cstring>
#include "classic.h"

Classic::Classic(const char * s1, const char * s2, const char * s3, int n, double x)
: Cd(s2, s3, n, x)
{
	mainworks = new char[std::strlen(s1) + 1];
	std::strcpy(mainworks, s1);
}

Classic::Classic(const char * s1, const Cd & d)
: Cd(d)
{
	mainworks = new char[std::strlen(s1) + 1];
	std::strcpy(mainworks, s1);
}

Classic::Classic(const Classic & c)
: Cd(c)
{
	mainworks = new char[std::strlen(c.mainworks) + 1];
	std::strcpy(mainworks, c.mainworks);
}

Classic::Classic()
: Cd()
{
	mainworks = nullptr;
}

Classic::~Classic() {
	delete [] mainworks;
}

Classic & Classic::operator=(const Classic & c) {
	if (this == &c)
		return *this;
	Cd::operator=(c);
	delete [] mainworks;
	mainworks = new char[std::strlen(c.mainworks) + 1];
	std::strcpy(mainworks, c.mainworks);
	return *this;
}

void Classic::Report() const {
	Cd::Report();
	std::cout << "Main works: " << mainworks << std::endl;
}
