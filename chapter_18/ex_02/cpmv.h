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
	
	Cpmv & operator=(const Cpmv & cm) {	// copy & swap
#ifdef VERBOSE_
		MESG_("Cpmv& Cpmv::operator=(const Cpmv&) called");
#endif
		Cpmv temp = cm;
		swap(temp);
		return *this;
	}
	
	Cpmv & operator=(Cpmv && cm) {		// move & swap
#ifdef VERBOSE_
		MESG_("Cpmv& Cpmv::operator=(Cpmv&&) called");
#endif
		swap(cm);
		return *this;
	}
	
//  可以将上面的复制赋值运算符和移动赋值运算符写成一个函数：
//	Cpmv & operator=(Cpmv cm) {		// copy/move & swap
//#ifdef VERBOSE_
//		MESG_("Cpmv& Cpmv::operator=(Cpmv) called");
//#endif
//		swap(cm);
//		return *this;
//	}
	
	void swap(Cpmv & cm) noexcept {
#ifdef VERBOSE_
		MESG_("void Cpmv::swap(Cpmv&) called");
#endif
		// 下面是更通用的写法，但这里不需要这样写：
		// using std::swap;
		// swap(pi, cm.pi);
		std::swap(pi, cm.pi);
	}
	
	void display() const;
	
//  可以将4个加法运算符的重载写成成员函数，从C++23开始，也可以使用
//  显式对象形参来编写成员函数，但使用非成员函数（包括友元函数）是
//  更通常的写法：
//	Cpmv operator+(const Cpmv & cm) const & {
//#ifdef VERBOSE_
//		MESG_("Cpmv Cpmv::operator+(const Cpmv&) const & called");
//#endif
//		return Cpmv(first(*this) + first(cm),
//					second(*this) + second(cm));
//	}
//	
//	Cpmv operator+(Cpmv && cm) && {
//#ifdef VERBOSE_
//		MESG_("Cpmv Cpmv::operator+(Cpmv&&) && called");
//#endif
//		using std::move;
//		return Cpmv(first(move(*this)) + first(move(cm)),
//					second(move(*this)) + second(move(cm)));
//	}
//	
//	Cpmv operator+(Cpmv && cm) const & {
//#ifdef VERBOSE_
//		MESG_("Cpmv Cpmv::operator+(Cpmv&&) const & called");
//#endif
//		using std::move;
//		return Cpmv(first(*this) + first(move(cm)),
//					second(*this) + second(move(cm)));
//	}
//	
//	Cpmv operator+(const Cpmv & cm) && {
//#ifdef VERBOSE_
//		MESG_("Cpmv Cpmv::operator+(const Cpmv&) && called");
//#endif
//		using std::move;
//		return Cpmv(first(move(*this)) + first(cm),
//					second(move(*this)) + second(cm));
//	}
	
	friend const first_type & first(const Cpmv & cm)
		{ return (*cm.pi).first; }
	friend first_type && first(Cpmv && cm)
		{ return std::move( (*cm.pi).first ); }
	friend const second_type & second(const Cpmv & cm)
		{ return (*cm.pi).second; }
	friend second_type && second(Cpmv && cm)
		{ return std::move( (*cm.pi).second ); }
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
	// 这里的 first() 和 second() 是通过 ADL 找到的，常规的名字查找
	// 规则是无法找到定义在类 Cpmv 内的函数 first() 和 second() 的。
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
