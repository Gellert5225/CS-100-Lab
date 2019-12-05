#ifndef __PAREN_HPP__
#define __PAREN_HPP__

#include "Modify.hpp"

class Paren : public Modify {
public:
	Paren(Base* b);

	double evaluate();
	std::string stringify();
	Iterator* create_iterator();

	Base* get_left();
    Base* get_right();

	void accept(CountVisitor*);
};
#endif

