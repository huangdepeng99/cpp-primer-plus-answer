#include <cstring>
#include "vintageport.h"

VintagePort::VintagePort()
// : Port()
{
	const char *nn = "none";
	nickname = new char[std::strlen(nn) + 1];
	std::strcpy(nickname, nn);
	year = 0;
}

VintagePort::VintagePort(const char * nn, int y, const char * br,
						 const char * st, int b)
: Port(br, st, b)
{
	nickname = new char[std::strlen(nn) + 1];
	std::strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const char * nn, int y, const Port & p)
: Port(p)
{
	nickname = new char[std::strlen(nn) + 1];
	std::strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort & vp)
: Port(vp)
{
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp) {
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	delete [] nickname;
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}

void VintagePort::Show() const {
	Port::Show();
	std::cout << "Nickname: " << nickname << std::endl
			  << "Year: " << year << std::endl;
}

std::ostream & operator<<(std::ostream & os, const VintagePort & vp) {
	os << dynamic_cast<const Port &> (vp);
	os << ", " << vp.nickname << ", " << vp.year;
	return os;
}
