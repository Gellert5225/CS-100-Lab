#ifndef __MULT_HPP__
#define __MULT_HPP__

#include <sstream>
#include "base.hpp"
#include <iostream>

class Mult : public Base {

public:
	Mult(Base* op1, Base* op2):Base() {
		multiplicant = op1;
		multiplier = op2;
	}
	virtual double evaluate() {
		return multiplicant->evaluate() * multiplier->evaluate();  
	}
	virtual std::string stringify() { 
		std::stringstream out;
		out << multiplicant->stringify() << " * " << multiplier->stringify();
		return out.str();
	}

	Iterator* create_iterator() {
		return new BinaryIterator(this);
	}

	Base* get_left() {
		return multiplicant;
	}

	Base* get_right() {
		return multiplier;
	}
private:
	Base* multiplicant;
	Base* multiplier;

};

#endif
