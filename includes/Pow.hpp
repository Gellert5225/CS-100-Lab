#ifndef __POW_HPP__
#define __POW_HPP__

#include <sstream>
#include "base.hpp"
#include <iostream>
#include <cmath>

class Pow : public Base {

public:
        Pow(Base* op1, Base* op2):Base() {
                Root = op1;
                Exponent = op2;
        }
        virtual double evaluate() {return pow(Root->evaluate(), Exponent->evaluate()); }
        virtual std::string stringify(){
                std::stringstream out;
                out << Root->stringify() << " ** " <<Exponent->stringify();
                return out.str();
        }

        Iterator* create_iterator() {
                return new BinaryIterator(this);
        }

        Base* get_left() {
                return Root;
        }

        Base* get_right() {
                return Exponent;
        }

        void accept(CountVisitor* cv) {
                cv->visit_pow();
        }
private:
        Base* Root;
        Base* Exponent;
};

#endif

