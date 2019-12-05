#include "../includes/Ceil.hpp"
#include <sstream>

Ceil::Ceil(Base* b):
    Modify(b) {}

double Ceil::evaluate() {
    return ceil(this->base->evaluate());
}

std::string Ceil::stringify() {
    std::stringstream out;
    out << ceil(this->base->evaluate());
    return out.str();
}

Iterator* Ceil::create_iterator() {
    return new UnaryIterator(this);
}

Base* Ceil::get_left() {
    return base;
}

Base* Ceil::get_right() {
    return base;
}
