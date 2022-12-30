#ifndef _CLASSIC_H_
#define _CLASSIC_H_
#include "cd.h"

class Classic final : public Cd {
private:
	char mainworks[100];
public:
	Classic(const char * s1, const char * s2, const char * s3, int n, double x);
	Classic(const char * s1, const Cd & d);
	Classic();
	void Report() const override;
};
#endif
