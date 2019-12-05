#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
class Iterator;
#include "iterator.hpp"

class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
        virtual Iterator* create_iterator() = 0;

        virtual Base* get_left() = 0;
        virtual Base* get_right() = 0;
    private:
        Base* left;
        Base* right;
};

#endif //__BASE_HPP__
