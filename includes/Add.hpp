#ifndef __ADD_HPP__
#define __ADD_HPP__

#include <sstream>
#include "base.hpp"
#include <iostream>

class Add : public Base {

public:
	Add(Base* op1, Base* op2):Base() {
		Augend = op1;
		Addend = op2;
	}
	virtual double evaluate() {
		return Augend->evaluate() + Addend->evaluate(); 
	}
	virtual std::string stringify() {
		std::stringstream out;
		out << Augend->stringify() << " + " <<Addend->stringify();
		return out.str();
	}

	Iterator* create_iterator() {
		return new BinaryIterator(this);
	}

	Base* get_left() {
		return Augend;
	}

	Base* get_right() {
		return Addend;
	}

	void accept(CountVisitor* cv) {
		cv->visit_add();
	}
private:
	Base* Augend;
	Base* Addend;
};

#endif
