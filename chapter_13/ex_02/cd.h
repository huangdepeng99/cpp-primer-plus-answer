#ifndef CD_H_
#define CD_H_
#include <iostream>

class Cd {
private:
	char *performers;
	char *label;
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
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();
	Cd & operator=(const Cd & d);
	virtual void Report() const;
};
#endif
