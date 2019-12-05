#ifndef __TRUNC_HPP__
#define __TRUNC_HPP__

#include "Modify.hpp"

class Trunc : public Modify {
public:
	Trunc(Base* b);

	double evaluate();
	std::string stringify();
	Iterator* create_iterator();

	Base* get_left();
    Base* get_right();

	void accept(CountVisitor*);
};
#endif
