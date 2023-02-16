#ifndef CPMV_H_
#define CPMV_H_

#include <string>
#include <utility>	// std::pair, std::move, std::swap

#ifdef VERBOSE_
#include <iostream>
#define MESG_(S_) do { std::cout << S_ << std::endl; } while (0)
#endif

// begin class Cpmv
class Cpmv {
public:
	using Info = std::pair<std::string, std::string>;
	using first_type = Info::first_type;
	using second_type = Info::second_type;
private:
	Info * pi = nullptr;
	
	friend const first_type & first(const Cpmv & cm)
		{ return (*cm.pi).first; }
	friend first_type && first(Cpmv && cm)
		{ return std::move( (*cm.pi).first ); }
	friend const second_type & second(const Cpmv & cm)
		{ return (*cm.pi).second; }
	friend second_type && second(Cpmv && cm)
		{ return std::move( (*cm.pi).second ); }
public:
#ifdef VERBOSE_
	Cpmv() { MESG_("Cpmv::Cpmv() called"); }
#else
	constexpr Cpmv() = default;
#endif
	
	Cpmv(const first_type & fst, const second_type & snd)
	: pi(new Info (fst, snd))
#ifdef VERBOSE_
	{ MESG_("Cpmv::Cpmv(const string&, const string&) called"); }
#else
	{ }
#endif
	
	Cpmv(first_type && fst, second_type && snd)
	: pi(new Info (std::move(fst), std::move(snd)))
#ifdef VERBOSE_
	{ MESG_("Cpmv::Cpmv(string&&, string&&) called"); }
#else
	{ }
#endif
	
	Cpmv(const Cpmv & cm)
	: pi(cm.pi ? new Info (*(cm.pi)) : nullptr)
#ifdef VERBOSE_
	{ MESG_("Cpmv::Cpmv(const Cpmv&) called"); }
#else
	{ }
#endif
	
	Cpmv(Cpmv && cm) {
#ifdef VERBOSE_
		MESG_("Cpmv::Cpmv(Cpmv&&) called");
#endif
		swap(cm);
	}
	
	~Cpmv() {
#ifdef VERBOSE_
		MESG_("Cpmv::~Cpmv() called");
#endif
		delete pi;
	}
	
	Cpmv & operator=(Cpmv cm) {		// copy/move & swap
#ifdef VERBOSE_
		MESG_("Cpmv& Cpmv::operator=(Cpmv) called");
#endif
		swap(cm);
		return *this;
	}
	
	void swap(Cpmv & cm) noexcept {
#ifdef VERBOSE_
		MESG_("void Cpmv::swap(Cpmv&) called");
#endif
		// no need:
		// using std::swap;
		// swap(pi, cm.pi);
		std::swap(pi, cm.pi);
	}
	
	void display() const;
	
	friend Cpmv operator+(const Cpmv & lhs, const Cpmv & rhs);
	friend Cpmv operator+(Cpmv && lhs, Cpmv && rhs);
	friend Cpmv operator+(const Cpmv & lhs, Cpmv && rhs);
	friend Cpmv operator+(Cpmv && lhs, const Cpmv & rhs);
};	// end class Cpmv


inline void swap(Cpmv & cm1, Cpmv & cm2) noexcept {
#ifdef VERBOSE_
	MESG_("void swap(Cpmv&, Cpmv&) called");
#endif
	cm1.swap(cm2);
}

inline Cpmv operator+(const Cpmv & lhs, const Cpmv & rhs) {
#ifdef VERBOSE_
	MESG_("Cpmv operator+(const Cpmv&, const Cpmv&) called");
#endif
	return Cpmv(first(lhs) + first(rhs),
				second(lhs) + second(rhs));
}

inline Cpmv operator+(Cpmv && lhs, Cpmv && rhs) {
#ifdef VERBOSE_
	MESG_("Cpmv operator+(Cpmv&&, Cpmv&&) called");
#endif
	using std::move;
	return Cpmv(first(move(lhs)) + first(move(rhs)),
				second(move(lhs)) + second(move(rhs)));
}

inline Cpmv operator+(const Cpmv & lhs, Cpmv && rhs) {
#ifdef VERBOSE_
	MESG_("Cpmv operator+(const Cpmv&, Cpmv&&) called");
#endif
	using std::move;
	return Cpmv(first(lhs) + first(move(rhs)),
				second(lhs) + second(move(rhs)));
}

inline Cpmv operator+(Cpmv && lhs, const Cpmv & rhs) {
#ifdef VERBOSE_
	MESG_("Cpmv operator+(Cpmv&&, const Cpmv&) called");
#endif
	using std::move;
	return Cpmv(first(move(lhs)) + first(rhs),
				second(move(lhs)) + second(rhs));
}

#endif
