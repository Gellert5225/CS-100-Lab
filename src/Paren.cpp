#include "../includes/Paren.hpp"
#include <sstream>

Paren::Paren(Base* b):
        Modify(b) {}

double Paren::evaluate() {
	return this->base->evaluate();
}

std::string Paren::stringify() {
	std::stringstream out;
	out << "(" << this->base->stringify() << ")";
	return out.str();
}

Iterator* Paren::create_iterator() {
	return new UnaryIterator(this);
}

Base* Paren::get_left() {
    return base;
}

Base* Paren::get_right() {
    return base;
}

void Paren::accept(CountVisitor* cv) {
    cv->visit_paren();
}