#include <iostream>
#include <cstring>
#include "dma.h"

// topDMA methods
topDMA::topDMA(const char * l, int r) {
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

topDMA::topDMA(const topDMA & rs) {
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

topDMA::~topDMA() {
    delete [] label;
}

topDMA & topDMA::operator=(const topDMA & rs) {
	if (this == &rs)
		return *this;
	delete [] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

void topDMA::View() const {
	std::cout << "Label: " << label << std::endl;
	std::cout << "Rating: " << rating << std::endl;
}

// baseDMA methods
baseDMA::baseDMA(const char * l, int r)
: topDMA(l, r)
{ }

baseDMA::baseDMA(const topDMA & rs)
: topDMA(rs)
{ }

baseDMA & baseDMA::operator=(const topDMA & rs) {
	if (this == &rs)
		return *this;
	topDMA::operator=(rs);
	return *this;
}
void baseDMA::View() const {
	topDMA::View();
}

// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, int r)
: topDMA(l, r)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char * c, const topDMA & rs)
: topDMA(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

void lacksDMA::View() const {
	topDMA::View();
	std::cout << "Color: " << color << std::endl;
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r)
: topDMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const topDMA & rs)
: topDMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & rs)
: topDMA(rs)
{
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
}

hasDMA::~hasDMA() {
	delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & rs) {
	if (this == &rs)
		return *this;
	topDMA::operator=(rs);
	delete [] style;
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
	return *this;
}

void hasDMA::View() const {
	topDMA::View();
    std::cout << "Style: " << style << std::endl;
}
