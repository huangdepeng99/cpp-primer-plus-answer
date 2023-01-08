#ifndef _WINEI_H_
#define _WINEI_H_
#include <string>
#include <valarray>
#include "pairs.h"

// using ArrayInt = std::valarray<int>;
typedef std::valarray<int> ArrayInt;
// using PairArray = Pair<ArrayInt, ArrayInt>;
typedef Pair<ArrayInt, ArrayInt> PairArray;

// class Wine final : private std::string, private PairArray {
class Wine final : std::string, PairArray {
private:
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
