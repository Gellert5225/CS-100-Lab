#ifndef __CEIL_HPP__
#define __CEIL_HPP__

#include <cmath>
#include "Modify.hpp"

class Ceil : public Modify {
public:
    Ceil(Base* b);

    double evaluate();
    std::string stringify();
    Iterator* create_iterator();

    Base* get_left();
    Base* get_right();

    void accept(CountVisitor*);
};

#endif
