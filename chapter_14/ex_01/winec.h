#ifndef WINEC_H_
#define WINEC_H_
#include <string>
#include <valarray>
#include "pairs.h"

class Wine {
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	
	std::string label;
	PairArray pa;
	int years;
public:
	Wine();
	Wine(const char * l, int y, const int yr[], const int bot[]);
	Wine(const char * l, int y);
	void GetBottles();
	const std::string & Label() const;
	int sum() const;
	void Show() const;
};

#endif
