#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__

#include <cmath>
#include "Modify.hpp"

class Floor : public Modify {
public:
    Floor(Base* b);

    double evaluate();
    std::string stringify();
    Iterator* create_iterator();

    Base* get_left();
    Base* get_right();

    void accept(CountVisitor*);
};

#endif
