#ifndef __STRINGIFY_DECORATOR_TEST_HPP__
#define __STRINGIFY_DECORATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "Abs.hpp"
#include "Ceil.hpp"
#include "Floor.hpp"
#include "Add.hpp"
#include "Mult.hpp"
#include "Sub.hpp"
#include "Trunc.hpp"
#include "Paren.hpp"

Base* setupEquation2() {
    Op* sevenFive = new Op(7.5);
    Op* oneOne = new Op(1.1);
    Op* five = new Op(5);
    Op* half = new Op(0.5);
    Op* fortyFive = new Op(45.4);

    Add* add = new Add(sevenFive, oneOne);
    Mult* mult = new Mult(add, five);
    Add* add2 = new Add(mult, half);
    Sub* sub = new Sub(add2, fortyFive);

    return sub;
}

TEST(StringifyTestSet, TruncTest) {
    Base* equation = setupEquation2();
    Op* three = new Op(3);
    Op* five = new Op(5);
    Add* add = new Add(five, three);

    Trunc* t = new Trunc(add);

    Add* composite = new Add(equation, t);
    EXPECT_EQ(composite->stringify(), "7.5 + 1.1 * 5 + 0.5 - 45.4 + 8");
}

TEST(StringifyTestSet, ParenTest) {
    Base* equation = setupEquation2();
    Op* three = new Op(3);
    Op* five = new Op(5);
    Add* add = new Add(five, three);

    Paren* p = new Paren(add);

    Add* composite = new Add(equation, p);
    EXPECT_EQ(composite->stringify(), "7.5 + 1.1 * 5 + 0.5 - 45.4 + (5 + 3)");
}

TEST(StringifyTestSet, CrossTest) {
    Base* equation = setupEquation2();
    Op* three = new Op(3);
    Op* five = new Op(5);
    Add* add = new Add(five, three);
    
    Trunc* t = new Trunc(add);

    Op* seven = new Op(7);
    Op* four = new Op(4);
    Sub* sub = new Sub(seven, four);
    
    Paren* p = new Paren(sub);

    Floor* f = new Floor(equation);

    Add* composite = new Add(f, t);
    Sub* com = new Sub(composite, p);

    EXPECT_EQ(com->stringify(), "-2 + 8 - (7 - 4)");
} 
    




















#endif
