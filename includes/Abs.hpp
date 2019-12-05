#ifndef __ABS_HPP__
#define __ABS_HPP__

#include "Modify.hpp"

class Abs : public Modify {
public:
    Abs(Base* b);

    double evaluate();
    std::string stringify();
    Iterator* create_iterator();

    Base* get_left();
    Base* get_right();

    void accept(CountVisitor*);
};

#endif
