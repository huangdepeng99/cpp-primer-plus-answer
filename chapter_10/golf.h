#ifndef _GOLF_H_
#define _GOLF_H_
class golf {
private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;
public:
	golf(const char * name = "", int hc = 0);
	int setgolf();
	void sethandicap(int hc);
	void showgolf() const;
};
#endif
