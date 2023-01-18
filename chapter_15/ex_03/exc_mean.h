#include <iostream>
#include <string>
#include <stdexcept>

class bad_mean : public std::logic_error {
private:
	double a1;
	double a2;
protected:
	double first() const { return a1; }
	double second() const { return a2; }
public:
	bad_mean(double a, double b, const std::string & what_arg)
			: a1(a), a2(b), std::logic_error(what_arg) { }
	bad_mean(double a, double b, const char * what_arg)
			: a1(a), a2(b), std::logic_error(what_arg) { }
	virtual ~bad_mean() { }
	virtual void mesg() const;
};

inline void bad_mean::mesg() const {
	std::cout << std::logic_error::what() << std::endl
			  << "Values used: " << a1 << ", " << a2 << std:: endl;
}

class bad_hmean : public bad_mean {
public:
    bad_hmean(double a, double b,
			  const std::string & what_arg)
			: bad_mean(a, b, what_arg) { }
    bad_hmean(double a, double b,
			  const char * what_arg = "Bad arguments to hmean(): a = -b")
			: bad_mean(a, b, what_arg) { }
	virtual ~bad_hmean() { }
	using bad_mean::mesg;
};

class bad_gmean : public bad_mean {
public:
    bad_gmean(double a, double b,
			  const std::string & what_arg)
			: bad_mean(a, b, what_arg) { }
    bad_gmean(double a, double b,
			  const char * what_arg = "Bad arguments to gmean(): arguments should be >= 0")
			: bad_mean(a, b, what_arg) { }
	virtual ~bad_gmean() { }
    void mesg() const override;
};

inline void bad_gmean::mesg() const {
	std::cout << std::logic_error::what() << std::endl
			  << "gmean(" << first() << ", " << second() << ")" << std:: endl;
}
