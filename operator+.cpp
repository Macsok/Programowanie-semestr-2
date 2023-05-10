#include <iostream>

class ComplexNumber {
private:
	double re;
	double im;
public:
	//	initialization list
	explicit ComplexNumber(double r = 0, double i = 0) : re{ r }, im{ i } {}
	void show() const { std::cout << re << " " << im << std::endl; }

	ComplexNumber operator+(const ComplexNumber& c) const {
		ComplexNumber comp;
		comp.re = this->re + c.re;
		comp.im = this->im + c.im;
		return comp;
	}
};

int main() {
	ComplexNumber z1;
	ComplexNumber z2{ 2 };
	ComplexNumber z3{ 2, 5 };

	z1.show();
	z2.show();
	z3.show();

	z1 = z2 + z3;

	z1.show();
	return 0;
}