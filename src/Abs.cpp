#include "../includes/Abs.hpp"
#include <sstream>
#include <cmath>

Abs::Abs(Base* b):
    Modify(b) {}

double Abs::evaluate() {
    return abs(this->base->evaluate());
}

std::string Abs::stringify() {
    std::stringstream out;
    out << abs(this->base->evaluate());
    return out.str();
}

Iterator* Abs::create_iterator() {
    return new UnaryIterator(this);
}

Base* Abs::get_left() {
    return base;
}

Base* Abs::get_right() {
    return base;
}
