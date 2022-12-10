#ifndef _PLORG_H_
#define _PLORG_H_
class Plorg {
private:
	static const int Len = 20;
	char name[Len];
	int ci;
public:
	Plorg(const char * nm = "Plorga", int c = 50);
	void setci(int c);
	void show() const;
};
#endif
