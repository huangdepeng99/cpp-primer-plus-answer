#ifndef _COMPLEX0_H_
#define _COMPLEX0_H_
#include <iostream>

namespace COMPLEX {
	class Complex {
	private:
		double c_real;
		double c_imaginary;
	public:
		Complex() { c_real = c_imaginary = 0.0; }
		Complex(double r, double i) { c_real = r; c_imaginary = i; }
		double real() const { return c_real; }
		void real(double val) { c_real = val; }
		double imag() const { return c_imaginary; }
		void imag(double val) { c_imaginary = val; }
		Complex operator+(const Complex & c) const;
		Complex operator-(const Complex & c) const;
		Complex operator*(const Complex & c) const;
		Complex operator*(double d) const;
		friend Complex operator*(double d, const Complex & c);
		Complex operator~() const;
		friend std::ostream & operator<<(std::ostream & os, const Complex & c);
		friend std::istream & operator>>(std::istream & is, Complex & c);
	};
}
#endif
