#ifndef _CLASSIC_H_
#define _CLASSIC_H_
#include "cd.h"

class Classic final : public Cd {
private:
	char *mainworks;
public:
	Classic(const char * s1, const char * s2, const char * s3, int n, double x);
	Classic(const char * s1, const Cd & d);
	Classic(const Classic & c);
	Classic();
	~Classic();
	Classic & operator=(const Classic & c);
	virtual void Report() const;
};
#endif
