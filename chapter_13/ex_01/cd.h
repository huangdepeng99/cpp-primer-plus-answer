#ifndef _CD_H_
#define _CD_H_
#include <iostream>

class Cd {
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
protected:
	struct Formatting {
		std::ios_base::fmtflags ff;
		std::streamsize prec;
	};
	static Formatting SetFormat();
	static void Restore(const Formatting & f);
public:
	Cd(const char * s1, const char * s2, int n, double x);
	Cd();
	virtual ~Cd() { }
	virtual void Report() const;
};
#endif
