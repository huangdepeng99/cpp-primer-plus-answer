// stonewt.cpp -- Stonewt methods
#include <iostream>
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs) {
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;
    pds_left = lbs;
    pounds =  stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt() {		// default constructor, wt = 0
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() { }		// destructor

// show weight in stones
void Stonewt::show_stn() const {
	std::cout << stone << " stone, " << pds_left << " pounds" << std::endl;
}

// show weight in pounds
void Stonewt::show_lbs() const {
	std::cout << pounds << " pounds" << std::endl;
}

bool Stonewt::operator== (const Stonewt & s) const {
	return !this->compare(s);
}

bool Stonewt::operator!= (const Stonewt & s) const {
	return this->compare(s);
}

bool Stonewt::operator> (const Stonewt & s) const {
	return this->compare(s) > 0.0;
}

bool Stonewt::operator>= (const Stonewt & s) const {
	return this->compare(s) >= 0.0;
}

bool Stonewt::operator< (const Stonewt & s) const {
	return this->compare(s) < 0.0;
}

bool Stonewt::operator<= (const Stonewt & s) const {
	return this->compare(s) <= 0.0;
}
