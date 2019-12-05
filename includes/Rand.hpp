#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {

public:
	Rand():Base() {
		operand = std::rand() % 100;
	}
	virtual double evaluate() { return operand; }
	virtual std::string stringify() { return std::to_string(operand);  }
private:
	double operand;
};

#endif
