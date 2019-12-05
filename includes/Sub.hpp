#ifndef __SUB_HPP__
#define __SUB_HPP__

#include <sstream>
#include "base.hpp"
#include <iostream>

class Sub : public Base {
public:
        Sub(Base* op1, Base* op2):Base() {
                Minuend = op1;
                Subtrahend = op2;
        }
        virtual double evaluate() {return Minuend->evaluate() - Subtrahend->evaluate(); }
        virtual std::string stringify(){
                std::stringstream out;
                out << Minuend->stringify() << " - " <<Subtrahend->stringify();
                return out.str();
        }

        Iterator* create_iterator() {
		return new BinaryIterator(this);
	}
        
        Base* get_left() {
                return Minuend;
        }

        Base* get_right() {
                return Subtrahend;
        }

        void accept(CountVisitor* cv) {
                cv->visit_sub();
        }
private:
        Base* Minuend;
        Base* Subtrahend;
};

#endif

