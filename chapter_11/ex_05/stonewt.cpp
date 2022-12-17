// stonewt.cpp -- Stonewt methods
#include "stonewt.h"

void Stonewt::set_lbs() {
	pounds = stone * Lbs_per_stn + pds_left;
}

void Stonewt::set_stn() {
	stone = int(pounds) / Lbs_per_stn;    // integer division
	pds_left = int(pounds) % Lbs_per_stn + pounds - int(pounds);
}

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, Mode form) {
    pounds = lbs;
	mode = form;
	set_stn();
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, Mode form) {
    stone = stn;
    pds_left = lbs;
	mode = form;
    set_lbs();
}

Stonewt::Stonewt() {		// default constructor, wt = 0
    stone = pounds = pds_left = 0;
	mode = LBS;
}

Stonewt::~Stonewt() { }		// destructor

Stonewt Stonewt::operator+(const Stonewt & sw) const {
	return Stonewt(pounds + sw.pounds);	
}

Stonewt Stonewt::operator-(const Stonewt & sw) const {
	return Stonewt(pounds - sw.pounds);
}

Stonewt Stonewt::operator*(double m) const {
	return Stonewt(pounds * m);
}

Stonewt operator*(double m, const Stonewt & sw) {
	return sw * m;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & sw) {
	if (sw.mode == Stonewt::LBS)
		os <<  sw.pounds << " pounds";
	else if (sw.mode == Stonewt::STN)
		os << sw.stone << " stone, " << sw.pds_left << " pounds";
	else
		os << "Stonewt object mode is invalid";
	return os;
}
