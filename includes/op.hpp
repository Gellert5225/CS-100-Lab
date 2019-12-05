#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <sstream>
#include <iostream>

class Op : public Base {

public:
        Op(double value) : Base() {
                operand = value;		

        }
        virtual double evaluate() {
                return operand; 
        }
        virtual std::string stringify() { 
                std::ostringstream out;
                out << operand;
                return out.str();
        }
        Iterator* create_iterator() {
                return new NullIterator(this);
        }

        Base* get_left() {
                return nullptr;
        }
        Base* get_right() {
                return nullptr;
        }

private:
	double operand;
};

class Op_1 : public Base {

public:
	Op_1() : Base() { }
        virtual double evaluate() { return -1; }
        virtual std::string stringify() { return "-1"; }

};

class Op_2 : public Base {

public:
        Op_2() : Base() { }
        virtual double evaluate() { return 20.01; }
        virtual std::string stringify() { return "20.01"; }

};

class Op_3 : public Base {

public:
        Op_3() : Base() { }
        virtual double evaluate() { return 256; }
        virtual std::string stringify() { return "256"; }

};



#endif //__OP_HPP__
