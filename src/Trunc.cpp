#include "../includes/Trunc.hpp"
#include <sstream>

Trunc::Trunc(Base* b):
	Modify(b) {}

double Trunc::evaluate() {
	return this->base->evaluate();
}

std::string Trunc::stringify() {
	std::stringstream out;
	out << this->base->evaluate();
	return out.str();
}

Iterator* Trunc::create_iterator() {
	return new UnaryIterator(this);
}

Base* Trunc::get_left() {
    return base;
}

Base* Trunc::get_right() {
    return base;
}

void Trunc::accept(CountVisitor* cv) {
    cv->visit_trunc();
}