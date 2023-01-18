#include <string>
#include <stdexcept>

class bad_hmean : public std::logic_error {
public:
	explicit bad_hmean(const std::string & what_arg) : std::logic_error(what_arg) { }
	explicit bad_hmean(const char * what_arg) : std::logic_error(what_arg) { }
	virtual ~bad_hmean() { }
};

class bad_gmean : public std::logic_error {
public:
	explicit bad_gmean(const std::string & what_arg) : std::logic_error(what_arg) { }
	explicit bad_gmean(const char * what_arg) : std::logic_error(what_arg) { }
	virtual ~bad_gmean() { }
};
