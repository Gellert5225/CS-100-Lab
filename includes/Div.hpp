#ifndef __DIV_H__
#define __DIV_H__

#include <stdexcept>
#include <sstream>
#include "base.hpp"

class Div: public Base {
public:
	Div(Base* op1, Base* op2): Base() {
		divident = op1;
		divisor = op2;
	}
	virtual double evaluate() { 
		if (divisor->evaluate() == 0.0) throw std::runtime_error("Cannot divide by zero!");
		else return divident->evaluate() / divisor->evaluate();
	}
	virtual std::string stringify() {
		std::stringstream out;
		out << divident->stringify() << " / " << divisor->stringify();
		return out.str();
	}

	Iterator* create_iterator() {
		return new BinaryIterator(this);
	}

	Base* get_left() {
		return divident;
	}

	Base* get_right() {
		return divisor;
	}

	void accept(CountVisitor* cv) {
		cv->visit_div();
	}
private:
	Base* divident;
	Base* divisor;
};

#endif
