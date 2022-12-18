#include "complex0.h"

namespace COMPLEX {
	Complex Complex::operator+(const Complex & c) const {
		return Complex(c_real + c.c_real, c_imaginary + c.c_imaginary);
	}
	
	Complex Complex::operator-(const Complex & c) const {
		return Complex(c_real - c.c_real, c_imaginary - c.c_imaginary);
	}
	
	Complex Complex::operator*(const Complex & c) const {
		return Complex(c_real * c.c_real - c_imaginary * c.c_imaginary,
						c_real * c.c_imaginary + c_imaginary * c.c_real);
	}
	
	Complex Complex::operator*(double d) const {
		return Complex(c_real * d, c_imaginary * d);
	}
	
	Complex operator*(double d, const Complex & c) {
		return c * d;
	}
	
	Complex Complex::operator~() const {
		return Complex(c_real, -c_imaginary);
	}
	
	std::ostream & operator<<(std::ostream & os, const Complex & c) {
		os << "(" << c.c_real << "," << c.c_imaginary << "i)";
		return os;
	}
	
	std::istream & operator>>(std::istream & is, Complex & c) {
		std::cout << "real: ";
		is >> c.c_real;
		if (!is)
			return is;
		std::cout << "imaginary: ";
		is >> c.c_imaginary;
		is.get();
		return is;
	}
}
