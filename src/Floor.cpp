#include "../includes/Floor.hpp"
#include <sstream>

Floor::Floor(Base* b):
    Modify(b) {}

double Floor::evaluate() {
    return floor(this->base->evaluate());
}

std::string Floor::stringify() {
    std::stringstream out;
    out << floor(this->base->evaluate());
    return out.str();
}

Iterator* Floor::create_iterator() {
    return new UnaryIterator(this);
}

Base* Floor::get_left() {
    return base;
}

Base* Floor::get_right() {
    return base;
}

void Floor::accept(CountVisitor* cv) {
    cv->visit_floor();
}
