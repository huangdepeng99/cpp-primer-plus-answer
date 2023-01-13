#ifndef VINTAGEPORT_H_
#define VINTAGEPORT_H_
#include "port.h"

class VintagePort final : public Port {
private:
	char *nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char * nn, int y, const char * br, const char * st, int b);
	VintagePort(const char * nn, int y, const Port & p);
	VintagePort(const VintagePort & vp);
	~VintagePort() { delete [] nickname; };
	VintagePort & operator=(const VintagePort & vp);
	void Show() const override;
	friend std::ostream & operator<<(std::ostream & os, const VintagePort & vp);
};
#endif
