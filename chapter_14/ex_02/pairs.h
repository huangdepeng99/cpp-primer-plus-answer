#ifndef _PAIRS_H_
#define _PAIRS_H_

template <typename T1, typename T2>
class Pair {
private:
    T1 a;
    T2 b;
public:
    Pair() { }
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) { }
	virtual ~Pair() { }
    T1 & first() { return a; }
    T2 & second() { return b; }
    const T1 & first() const { return a; }
    const T2 & second() const { return b; }
};

#endif
