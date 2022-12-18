// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>
class Stonewt {
public:
	enum Mode {LBS, STN};
private:
    enum {Lbs_per_stn = 14};      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds
	Mode mode;
	void set_lbs();
	void set_stn();
public:
    explicit Stonewt(double lbs, Mode form = LBS);          // constructor for double pounds
    Stonewt(int stn, double lbs, Mode form = STN); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
	void lbs_mode() {mode = LBS;}
	void stn_mode() {mode = STN;}
	Stonewt operator+(const Stonewt & sw) const;
	Stonewt operator-(const Stonewt & sw) const;
	Stonewt operator*(double m) const;
	friend Stonewt operator*(double m, const Stonewt & sw);
    friend std::ostream & operator<<(std::ostream & os, const Stonewt & sw);
};
#endif
