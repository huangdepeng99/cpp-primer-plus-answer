#include <cstring>
#include "stock20.h"

// constructors
Stock::Stock() {		// default constructor
	company = nullptr;
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, long n, double pr) {
    company = new char[std::strlen(co) + 1];
	std::strcpy(company, co);
    if (n < 0) {
        std::cout << "Number of shares can't be negative; "
                   << company << " shares set to 0." << std::endl;
        shares = 0;
    } else
        shares = n;
    share_val = pr;
    set_tot();
}

Stock::Stock(const Stock & s) {
	company = new char[std::strlen(s.company) + 1];
	std::strcpy(company, s.company);
	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
}

// class destructor
Stock::~Stock() {		// destructor
	delete [] company;
}

Stock & Stock::operator=(const Stock & s) {
	if (this == &s)
		return *this;
	delete [] company;
	company = new char[std::strlen(s.company) + 1];
	std::strcpy(company, s.company);
	shares = s.shares;
	share_val = s.share_val;
	total_val = s.total_val;
	return *this;
}

// other methods
void Stock::buy(long num, double price) {
	if (num < 0) {
        std::cout << "Number of shares purchased can't be negative. "
             << "Transaction is aborted." << std::endl;
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    if (num < 0) {
		std::cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted." << std::endl;
    } else if (num > shares) {
		std::cout << "You can't sell more than you have! "
             << "Transaction is aborted." << std::endl;
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

std::ostream & operator<<(std::ostream & os, const Stock & s) {
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);
	
    os << "Company: " << s.company
	   << "  Shares: " << s.shares << std::endl;
    os << "  Share Price: $" << s.share_val;
    // set format to #.##
    os.precision(2);
    os << "  Total Worth: $" << s.total_val;
	
    // restore original format
    os.flags(orig);
    os.precision(prec);
	return os;
}

const Stock & Stock::topval(const Stock & s) const {
    if (s.total_val > total_val)
        return s;
    else
        return *this; 
}
